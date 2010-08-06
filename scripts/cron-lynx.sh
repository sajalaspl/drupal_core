#!/bin/sh
# $Id: cron-lynx.sh,v 1.1.1.1 2010/06/25 06:06:11 bhargav Exp $

/usr/bin/lynx -source http://example.com/cron.php > /dev/null 2>&1
