#!/usr/local/bin/perl

use File::Copy;
use File::Compare;
#use strict;

my $dynamicHeader = "HTTP/1.0 200 OK\r\nConnection: close\r\nContent-Type: text/html; charset=iso-8859-1\r\nPragma: no-cache\r\nExpires: 0\r\n\r\n";
my $staticHeader = "HTTP/1.0 200 OK\r\nConnection: close\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\n";
my $jpgHeader = "HTTP/1.0 200 OK\r\nConnection: close\r\nCache-Control: max-age=3600\r\nContent-Type: image/jpeg\r\n\r\n";
my $gifHeader = "HTTP/1.0 200 OK\r\nConnection: close\r\nCache-Control: max-age=3600\r\nContent-Type: image/gif\r\n\r\n";
my $pngHeader = "HTTP/1.0 200 OK\r\nConnection: close\r\nCache-Control: max-age=3600\r\nContent-Type: image/png\r\n\r\n";
my $jsHeader = "HTTP/1.0 200 OK\r\nConnection: close\r\nCache-Control: max-age=3600\r\nContent-Type: application/x-javascript; charset=iso-8859-1\r\n\r\n";
my $cssHeader = "HTTP/1.0 200 OK\r\nConnection: close\r\nCache-Control: max-age=3600\r\nContent-Type: text/css; charset=iso-8859-1\r\n\r\n";

if ( $#ARGV != 1 ) {
   print "\nUsage: html2c.pl baseName filetype\n";
   print "\nwhere filetype = 0 if dynamic content\n";
   print "      filetype = 1 if static content\n";
   print "      filetype = -1 if no header should be generated\n\n";
   exit 1;
}

my $inFile = $ARGV[0];
($fileName, $fileExt) = split /\./, $inFile;
my $cFile = $fileName . "\.xxc";
my $hFile = $fileName . "\.xxh";
my $orig_cFile = $fileName . "\.c";
my $orig_hFile = $fileName . "\.h";
my $size = uc $fileName . "_SIZE";
my $include = uc $fileName . "_H_INC";
my $mode = $ARGV[1];

open IN, "$inFile" or die "Can't open $inFile";

if ($fileExt eq "jpg") {
  $mode = 2;
  binmode IN;
}
elsif ($fileExt eq "gif") {
  $mode = 3;
  binmode IN;
}
elsif ($fileExt eq "png") {
  $mode = 4;
  binmode IN;
}
elsif ($fileExt eq "js") {
  $mode = 5;
  binmode IN;
}
elsif ($fileExt eq "css") {
  $mode = 6;
  binmode IN;
}
open C, ">$cFile" or die "Can't open $cFile";
open H, ">$hFile" or die "Can't open $hFile";

print C <<BEGIN_DECLARATION;
// This file was created by the html2c.pl utility
//

#include "common.h"
#include "$fileName.h"


const uchar  ${fileName}_${fileExt}[$size] =
{
BEGIN_DECLARATION

# Load up the header
#
my @chars = ();
my @buffer=();

if ( $mode == 0 ) {
   @chars = split //, $dynamicHeader;
}
elsif ( $mode == 1 ) {
   @chars = split //, $staticHeader;
}
elsif ( $mode == 2 ) {
   @chars = split //, $jpgHeader;
}
elsif ( $mode == 3 ) {
   @chars = split //, $gifHeader;
}
elsif ( $mode == 4 ) {
   @chars = split //, $pngHeader;
}
elsif ( $mode == 5 ) {
   @chars = split //, $jsHeader;
}
elsif ( $mode == 6 ) {
   @chars = split //, $cssHeader;
}



if ( $mode != -1 ) {
   foreach my $character (@chars) {
      $buffer[++$#buffer] = $character;
   }
}

while (<IN>) {

  if (!($fileExt eq "jpg") && !($fileExt eq "gif") && !($fileExt eq "png")) {
    s/^\s*//; # Remove leading whitespace
  }

  @chars = split //, $_;
   foreach my $character (@chars) {
      $buffer[++$#buffer] = $character;
   }
}
close IN;

my $col=0;
for (my $i=0; $i<$#buffer; $i++) {

   if ( $col == 8 ) {
      print C "\n";
      $col=0;
   }

   print C ' ';
   print C sprintf ("0x%02x, ", ord($buffer[$i])); 
   $col++;
}

if ( $col == 8 ) {
   print C "\n";
}

print C sprintf ("0x%02x};\n", ord($buffer[$#buffer])); 

close C;

### Bump the size since the array is zero based
#
$#buffer++;

print H <<INCLUDE_FILE;
// This file was created by the html2c.pl utility
//

#ifndef $include
#define $include

#define $size $#buffer

extern const uchar  ${fileName}_${fileExt}[$size];


#endif  // $include
INCLUDE_FILE

close H;

if (compare($cFile, $orig_cFile)) {
  move($cFile, $orig_cFile);
}
else {
  print "No change to $orig_cFile\n";
  unlink $cFile;
}

if (compare($hFile, $orig_hFile)) {
  move($hFile, $orig_hFile);
}
else {
  print "No change to $orig_hFile\n";
  unlink $hFile;
}

