#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void){
	pid_t pid;
	if((pid=fork()) < 0) {
		printf("\tfork error\n");
	}
	else if (pid == 0) {
		printf("Child process id is %d\n", getpid());
	}
	else {
		sleep(10);
		printf("******parent\n");
		system("ps -axj | tail");
	}
	exit(0);
}

/*
Child process id is 9809
******parent
   8952    9556    1129    1129 ?             -1 Sl    1000   0:00 /snap/firefox/4539/usr/lib/firefox/firefox -contentproc -childID 6 -isForBrowser -prefsLen 32540 -prefMapSize 248935 -jsInitLen 234780 -parentBuildID 20240704193811 -greomni /snap/firefox/4539/usr/lib/firefox/omni.ja -appomni /snap/firefox/4539/usr/lib/firefox/browser/omni.ja -appDir /snap/firefox/4539/usr/lib/firefox/browser {7a46ff41-4110-4eca-858c-61e7318c5933} 8952 true tab
      2    9582       0       0 ?             -1 I        0   0:00 [kworker/2:1]
      2    9696       0       0 ?             -1 I        0   0:00 [kworker/10:0-events]
      2    9697       0       0 ?             -1 I        0   0:00 [kworker/1:0-mm_percpu_wq]
      2    9740       0       0 ?             -1 I        0   0:00 [kworker/u32:3-events_power_efficient]
   3212    9808    9808    3212 pts/0       9808 S+    1000   0:00 ./a.out
   9808    9809    9808    3212 pts/0       9808 Z+    1000   0:00 [a.out] <defunct>
   9808    9813    9808    3212 pts/0       9808 S+    1000   0:00 sh -c ps -axj | tail
   9813    9814    9808    3212 pts/0       9808 R+    1000   0:00 ps -axj
   9813    9815    9808    3212 pts/0       9808 S+    1000   0:00 tail
*/

