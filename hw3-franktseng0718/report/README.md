# 作業 3 報告(使用VP)

> 學生：曾敏峰
>
> 學號：0616095


## 一開始的想法

   一開始真的完全完全沒有頭緒，說真的，因為我的OOP真的真的很爛，所以這次的作業我真的是從Virtual function,多型開始學的，慢慢有點概念後才開始寫的，開始寫後，第一個遇到的問題應該和大家一樣，就是要怎麼把那些rule一邊reduce一邊建出AST Node Tree，後來有了一個想法，就是把rule裡那些不用做的node也做出來，最後不要印就好，於是，因為想當然爾這絕對不是一兩天就能寫完的作業，我就快快加緊開始了。

## 寫的過程

  因為我是一次寫完再開始debug，所以寫的時候還滿順的，大概兩三天就把該寫的都完成了，原本以為哈哈哈，這個作業也沒什麼嘛，不過區區四五天就要被我做完了吧，但一編下去發現，error真是翻也翻不完阿，一開始是改Makefile的問題，因為那時候助教還沒拍影片，所以我自己研究了很久都弄不出來，後來索性將所有東西都寫在ast.h，再自己重寫一個Makefile就好，這個還有之後的一些無腦的error又花了我三天，開始寫的第六天，終於看到我的答案了，看了助教的測資後發現，自己少考慮了很多東西，例如StatementList會變成一種Statement然後又會再變StatementList這種code，因為我是用全域的指標去控制Node的parent-child關係，但如果是這樣的話，指標就會被改到導致做出來的樹會形成cycle，在dump的時候產生無窮迴圈，一開始我不知道是這個原因，一直很納悶，吃飯吃不好，睡覺也睡不著。嘿嘿嘿，直到有一天洗澡的時候，靈光乍現，發現了這個測資的箇中奧妙，我馬上隨便亂洗後衝回房間開始使用stack將原本指標的位置存起來。對的時候連我都不敢相信，只能說，謝謝爸爸媽媽給我生的聰明才智吧。

## 寫完幾天後

  寫完的有一天，助教發布了一部影片關於這次作業的一些提示，雖然我已經寫完了，但還是想說，看影片又不會很累，就看吧，當休息。裡面說到關於如何將原本的Makefile轉成C++的，於是，我又手癢開始改了，因為有對的Makefile了，我又索性將原本全部在ast.h裡的code部分移到visitor.h和visitor.c裡，畢竟這樣才是VP的真諦嘛。全部完成後雖然心力交瘁，眼睛黑腫得跟熊貓一樣，手也快沒知覺了，但，別懷疑，這是真的，這是我開始寫程式以來完成後最有成就感的一次。