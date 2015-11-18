#!/usr/local/bin/perl

use File::Copy;
use File::Compare;
use strict;

if ( $#ARGV != 0 ) {
   print "\nUsage: txt2c.pl <txtfile>\n";
   exit 1;
}

my $inFile = $ARGV[0];
my ($fileName, $fileExt) = split /\./, $inFile;
my $hFile = $fileName . "\.xxh";
my $cFile = $fileName . "\.xxc";
my $orig_hFile = $fileName . "\.h";
my $orig_cFile = $fileName . "\.c";
my $include = uc $fileName . "_H_INC";


my $enum_file_tmp = "enum.tmp";
my $ptrtab_file_tmp = "ptrtab.tmp";
my $string_file_tmp = "string.tmp";

my $txt_group_name;
my $txt_count;

my $state = 0;
my $txt_id;
my @txt_buf;
my $cmd_flag = 0;
my $prev_ch = 0;
my $string_start = 0;

sub enum_file_begin {
  print ENUMFILE "\n\ntypedef enum {\n";
}

sub enum_file_append {
  my ($id) = @_;

  print ENUMFILE "    ${id},\n";
}

sub enum_file_end {
  print ENUMFILE "} ${txt_group_name}_txt_t;\n\n\n";
}

sub ptrtab_file_begin {
  print PTRTABFILE "\n";

  print PTRTABFILE "\nconst struct {\n";
  print PTRTABFILE "    char far *str_ptr;\n";
  if ($cmd_flag) {
    print PTRTABFILE "    uchar min_match;  /* Minimum number of characters that must be present */\n";
  }
  print PTRTABFILE "} far ${txt_group_name}_txt_tab [] = {\n";
}

sub ptrtab_file_append {
  my ($id) = @_;

  print PTRTABFILE "    txt_${id},";
  if (!$cmd_flag) {
    print PTRTABFILE "\n";
  }
}

sub ptrtab_file_append_match {
  my ($min_match) = @_;

  print PTRTABFILE "${min_match},\n";
}

sub ptrtab_file_end {
  print PTRTABFILE "};\n";



}

sub string_file_begin {
  my ($id) = @_;

  print STRINGFILE "const char far txt_${id} [] = {";

  $string_start = 1;
}

sub string_file_append {
  my ($str) = @_;

  if (!$string_start) {
    print STRINGFILE "\n";
  }
  $string_start = 0;
  print STRINGFILE $str;

}

sub string_file_end {
  print STRINGFILE "};\n\n";

}

sub pass_line {
  my ($line) = @_;

  print ENUMFILE $line;
  print PTRTABFILE $line;
  print STRINGFILE $line;
}


sub txt_group_begin {

  open ENUMFILE,   ">$enum_file_tmp" or die "Can't open $enum_file_tmp";
  open PTRTABFILE, ">$ptrtab_file_tmp" or die "Can't open $ptrtab_file_tmp";
  open STRINGFILE, ">$string_file_tmp" or die "Can't open $string_file_tmp";
}

sub txt_group_end {

  print "Text group: $txt_group_name, max. number of texts: $txt_count\n";

  enum_file_end();
  ptrtab_file_end();
  
  close ENUMFILE;
  close PTRTABFILE;
  close STRINGFILE;

#
# Update target file with data for the text group
#
    print H "\n\n\n";
    print H "/* ************************************************************************ **\n";
    print H " *\n";
    print H " *\n";
    print H " * $txt_group_name texts\n";
    print H " *\n";
    print H " *\n";
    print H " *\n";
    print H " * ************************************************************************ */\n";

    print C "\n\n\n";
    print C "/* ************************************************************************ **\n";
    print C " *\n";
    print C " *\n";
    print C " * $txt_group_name texts\n";
    print C " *\n";
    print C " *\n";
    print C " *\n";
    print C " * ************************************************************************ */\n";

    open ENUMFILE, "$enum_file_tmp" or die "Can't open $enum_file_tmp";
    while (<ENUMFILE>) {
	print H $_;
    }

    open STRINGFILE, "$string_file_tmp" or die "Can't open $string_file_tmp";
    while (<STRINGFILE>) {
	print C $_;
    }
    open PTRTABFILE, "$ptrtab_file_tmp" or die "Can't open $ptrtab_file_tmp";
    while (<PTRTABFILE>) {
	print C $_;
    }
    close ENUMFILE;
    close PTRTABFILE;
    close STRINGFILE;

    unlink $enum_file_tmp;
    unlink $ptrtab_file_tmp;
    unlink $string_file_tmp;
}

sub retrieve_string {
  my ($str, $part) = @_;
  my @sub_str = ();
  my $check_end_delimiter = 0;
  my $get_min_match = 0;  
  my @min_match_buf = ();

  if ($part eq "start") {
    @txt_buf=();

    $txt_buf[++$#txt_buf] = '"';
    $prev_ch = '"';

    if ($str =~ /(.*)/) {
      my $hack= "\n";
      $str = join '', $str, $hack;
    }
    else {
      $state = 3;
      return;
    }
  }

  @sub_str = split //, $str;
  foreach my $ch (@sub_str) {
    if ($check_end_delimiter == 0) {
      $txt_buf[++$#txt_buf] = $ch;
      if ($ch eq '"' && $prev_ch ne '\\') {

        my $txt = join '', @txt_buf;
        string_file_append($txt);
        $check_end_delimiter = 1;
      };
      $prev_ch = $ch;
    }
    elsif ($get_min_match == 0) {
      if ($ch eq ',') {
        string_file_end();
        if ($cmd_flag) {
          $get_min_match = 1;
        }
        else {
          $state = 1;
          return;
        }
      }
      else {
        $state = 2;
        return;
      }
    }
    else {
      if ($ch eq ',') {
        my $min_match = join '', @min_match_buf;
        ptrtab_file_append_match($min_match);
        $state = 1;
        return;
      }
      else {
        $min_match_buf[++$#min_match_buf] = $ch;
      }
    }
  }
  $state = 3;
}

open IN, "<$inFile" or die "Can't open $inFile";
open H, ">$hFile" or die "Can't open $hFile";
open C, ">$cFile" or die "Can't open $cFile";

print H <<INCLUDE_DECLARATION;
// This file was created by the txt2c.pl utility based on file $inFile
//


#ifndef $include
#define $include

INCLUDE_DECLARATION

print C <<BEGIN_DECLARATION;
// This file was created by the txt2c.pl utility based on file $inFile
//

BEGIN_DECLARATION


my $remainder;

$state = 0;

while (<IN>) {

  if ($state == 0) {
    if ((/^%START_TXTGROUP\(([\w]+)\)/) ||
        (/^%START_CMDGROUP\(([\w]+)\)/)) {

      $txt_group_name = $1;

      if  (/^%START_CMDGROUP\(([\w]+)\)/) {
        $cmd_flag = 1;
      }
      else {
        $cmd_flag = 0;
      }

#      print "START_TXTGROUP $txt_group_name\n";
      $txt_count = 0;
      $state = 1;
      txt_group_begin();
      enum_file_begin();
      ptrtab_file_begin();
    }
  } elsif ($state == 1) {
    if (/^\#/) {
      pass_line($_);
    }
    elsif (/^%END_GROUP/) {
      txt_group_end();
      
      $state = 0;
    }
    else {
      if (/([\w]+)\s*,(.*)/) {
        $txt_id = $1;
        $remainder = $2;

        $txt_count = $txt_count + 1;
        
        enum_file_append($txt_id);
        ptrtab_file_append($txt_id);
        string_file_begin($txt_id);

        if ($remainder =~ /^\s*\"(.*)/) {
          retrieve_string($1, "start");
        }
        else {
          $state = 2;
        }
      }
      elsif (!/\s*/) {
        print "non empty line\r\n";
      }
    }
  } elsif ($state == 2) {
    # start quote (") of string expected
    if (/^\#/) {
      print STRINGFILE "\n$_";
    }
    elsif (/^%END_GROUP/) {
      txt_group_end();
      $state = 0;
    }
    elsif (/^\s*\"(.*)/) {
      retrieve_string($1, "start");
    }

  } elsif ($state == 3) {
    # retrieving string until end quote (")
    if (/^\#/) {
      print "# line found\n";
    }
    elsif (/^%END_GROUP/) {
      txt_group_end();
      
      $state = 0;
    }
    else {
      retrieve_string($_, "continued");
    }
  }
}

print H <<END_DECLARATION;


#endif  // $include

END_DECLARATION

close IN;
close H;
close C;

if (compare($hFile, $orig_hFile)) {
  move($hFile, $orig_hFile);
}
else {
  print "No change to $orig_hFile\n";
  unlink $hFile;
}
if (compare($cFile, $orig_cFile)) {
  move($cFile, $orig_cFile);
}
else {
  print "No change to $orig_cFile\n";
  unlink $cFile;
}
