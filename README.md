hw2：
map_cp並不支援file hole，請你撰寫一個程式稱之為mmap_cp2，mmap_cp2可以跳過file hole，只複製檔案中有真正內容的部分

hw3：
第⼀⽀程式稱之為 flock，他使⽤⼀個迴圈，共執⾏ 1000 次，在迴圈內先等待0.1 秒，然後在迴圈中將 flock.db 的最後⼀個數字讀出來(假設為 X)，並使⽤lseek 將檔案指標往前移動 X 個 byte，然後寫⼊值「X+1」。這個程式使⽤flock 函數確保⼀次只有⼀個程式更新 flock.db。flock.db 的第⼀個值是3500。
第⼆⽀程式稱之為 lockf，他使⽤⼀個迴圈，共執⾏ 1000 次，在迴圈內先等待0.1 秒，然後在迴圈中將 lockf.db 中的最後⼀個數字讀出來(假設為 X)，再使⽤ lseek 將檔案指標往前移動 X 個 byte，然後寫⼊值「X+1」。這個程式使⽤lockf 函數確保⼀次只有⼀個程式更新 lockf.db。lockf.db 的第⼀個值是3500。

hw4：
寫一支程式，程式的名稱是fileperf，這支程式接受二個參數，第一個參數是source_file，第二個參數是dest_file，第三個參數則是設定buffer_size，是一個數字，值可能是-1、0、或大於0的任何正整數（不會超過20MB）。
%~ ./fileperf source_file dest_file_1 1000 /*buffer size為1000 byte*/
%~ ./fileperf source_file dest_file_2 0 /*unbuffered, 0, 1024*/
%~ ./fileperf source_file dest_file_3 -1 /*linebuffered, 1024*/
source_file是一個幾乎是「英文」文字檔案（如果遇到並非ASCII的字元可以忽略，或者處理這些字元）。將source file的內容複製到dest_file。每一行的字數不能超過80個英文字（如果遇到要雙位元顯示的，例如：中文字，那就當成一個或二個字都可以）。請參考hw2_example目錄裡面的範例。記得，每一行最前面和最後面的空白要去掉，只有英文單字間的空白才可以換行。此外不會有單字是超過80個字。Buffer的設定同時套用到dest_file和source_file

hw5：
寫一支程式，程式名稱為preBirthday，無論誰執行這個檔案，都可以知道任何目錄下，所有「正規檔案」的「邏輯大小」的總和。例如：執行『preBirthday/』，會統計『根目錄』下所有的檔案。此外preBirthday會列出該目錄下有哪些檔案種類。

hw6：
寫一隻程式叫做myBusybox，並且建立如下的softlink，這些softlink都連接到myBusybox，myBusybox會依照softlink的名稱，使用system()執行相對應的功能
cp
ls
cat
chown

hw9：
寫一應用程式名稱為mylogin，每當使用者輸入姓名時，mylogin會判斷這個使用者是否可以進入伺服器，判斷的依據為該成員是否在/etc/passwd內。『不用輸入密碼』
如果可以進入伺服器，則login會產生一個child process，這個child process會設定適當的變數，然後執行『bash』
當使用者離開shell以後，要再跳出提示符號，讓使用者再次登入

hw13：
請參考pipe4-3的寫法，設計應用程式『fileCount /YYY』讓你的應用程式可以自動執行『ls -R /YYY | wc -l』計算/YYY目錄下大約有多少字元
請確保你的主程式『fileCount』收到ctr+c以後，可已讓『ls -R /YYY | wc -l』立即中止
