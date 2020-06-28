package main

import "fmt"

func main(){
	/*
	带缓冲的通道：  make(chan ，type， cap)
	缓冲通道： 只有在缓冲区 满了 或者空了才会发生阻塞
	*/
	ch0 := make(chan int)
	fmt.Println("ch0 size:",len(ch0),"ch0 cap :",cap(ch0))

	ch3 := make(chan int, 3)// 缓冲通道， 缓冲大小为5
	fmt.Println("ch3 size:",len(ch3),"ch3 cap :",cap(ch3))
	ch3 <- 3// ch3 带缓冲区的
	ch3 <- 4
	ch3 <- 5
	//ch3 <- 6// 缓冲区满了：发生阻塞了
	fmt.Println("ch3 size:",len(ch3),"ch3 cap :",cap(ch3))

	for i:= range ch3{
		fmt.Println(i)
	}




}
