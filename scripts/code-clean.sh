#!/bin/sh
# $Id: code-clean.sh,v 1.1.1.1 2010/06/25 06:06:11 bhargav Exp $

find . -name "*~" -type f | xargs rm -f
find . -name ".#*" -type f | xargs rm -f
find . -name "*.rej" -type f | xargs rm -f
find . -name "*.orig" -type f | xargs rm -f
find . -name "DEADJOE" -type f | xargs rm -f
find . -type f | grep -v ".psp" | grep -v ".gif" | grep -v ".jpg" | grep -v ".png" | grep -v ".tgz" | grep -v ".ico" | grep -v "druplicon" | xargs perl -wi -pe 's/\s+$/\n/'
find . -type f | grep -v ".psp" | grep -v ".gif" | grep -v ".jpg" | grep -v ".png" | grep -v ".tgz" | grep -v ".ico" | grep -v "druplicon" | xargs perl -wi -pe 's/\t/  /g'
