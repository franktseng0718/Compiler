
# 作業1 報告

學生 : 曾敏峰
學號 : 0616095

#How to run

$make
$./scanner <input file>

#Abilities

藉由lex的program,我們做出來的scanner會將input stream切成tokens,tokens就是會回傳給parser的,但在這個作業裡,我們只需要將token印出來就好。tokens又分為Keywords,identifiers,arithmetic,relational and logical operator,delimeters。comments和空白換行會被scanner略過不回傳，但在這個作業必須LIST到buffer裡print出來。

#Problems occurred

這個作業看似簡單但其實也花了我幾乎一整天的時間，主要的問題是，字串中間的雙引號連續兩個代表一個雙引號，這個我一開始真還沒想到怎麼做，後來才想說自己刻一個字串輸出的buffer，在這個buffer將多餘的雙引號去除才解決，另一個問題是，在描寫科學記號的時候，因不知道它是小數還是整數，所以在小數點後面加問號的情形下，會讓八進位的數也符合科學記號，後來反覆試驗後將小數與整數情形分開寫才解決，經過這次作業，我認為要實做出這個lex的scanner和上刻有認真聽完全不同，必須一行一行用自己的雙手打上去反覆實驗後才能完成，過程中雖然遇到許多奇怪的問題，但在發現問題之後，自己的程式實力確實進步了不少，也讓自己不再覺得自己是一個很廢，甚麼都寫不出來的大學生。
 
