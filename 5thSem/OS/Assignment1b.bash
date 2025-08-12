#!/bin/bash
mkdir assign
cd assign
mkdir part2
cd part2
cat > text.txt
Hello World
I am Jarvis
CTRL+D
cp text.txt text_copy.txt
mv text_copy.txt new_backup.txt
chmod 744 new_backup.txt
ls -l
