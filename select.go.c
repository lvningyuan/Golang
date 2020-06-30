package main

import (
	"fmt"
	"time"
)

func main() {
	/*
			select和 switch 语句非常相似
		    有多个case 可运行会随机运行一个，
			没有可以运行的 case 会阻塞等待，直到有case 可执行
	*/

	ch1 := make(chan int)
	ch2 := make(chan int)

	go func() {
		time.Sleep(1 * time.Second)
		ch1 <- 10
	}()
	go func() {
		time.Sleep(1 * time.Second)
		ch2 <- 20
	}()
	//下面我们进行  从通道ch1 ch2中读
	select {
	case num1 := <-ch1:
		fmt.Println("ch1 中获取数据->", num1)
	case num2, ok := <-ch2:
		if ok {
			fmt.Println("ch2 中读取的数据", num2)
		} else {
			fmt.Println("ch2 通道已经关闭...")
		}
	default:
		fmt.Println("default...")
	}
	fmt.Println("main over ...")
}
