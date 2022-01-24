# 作業2 報告

學生 :曾敏峰
學號 :0616095

--

## How to run

$make $./parser<input file>

## Abilities

藉由這個parser，我們可以檢查語法錯誤，例如連續寫三個加，或是沒加分號這種在lex我們無法辨認的情形，因為RE無法處理等號需要成對出現的情形，但在這個parser，我們藉由context-free language可以檢查這些錯誤。

## Problems occurred

這個作業看似簡單，但在我寫完grammar rule之後，出現了好幾十個conflict，雖然還是做對了test，但其實不太確定還有甚麼問題的。
