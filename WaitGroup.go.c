package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup //创建同步等待组对象

func func1(){
	for i:=0; i<10; i++{
		fmt.Println("func1 函数打印... A ",i)
	}
	defer wg.Done()// 该函数执行结束时： wg同步等待组中的goroutine数量 -1
}

func func2(){
	defer wg.Done()// 该函数执行结束时： wg同步等待组中的goroutine数量 -1
	for i:=0; i<10; i++{
		fmt.Println("\tfunc2 函数打印...  ",i)
	}
}

func main(){
	/*
		WaitGroup: 同步等待锁
		Add()设置等待组中要执行的 goroutine的数量
		Wait()  让主的goroutine等待
	*/
	wg.Add(2)// 我们目前有两个子的goroutine 要执行
	go func1()
	go func2()

	fmt.Println(" main 函数进入阻塞状态。。等待wg同步等待组中的goroutine全部结束")
	wg.Wait()// 表示 main  goroutine进入等待,意味着阻塞
	//当 wg中goroutine 数量为0时 ，主 goroutine解除阻塞
	fmt.Println("main  接触 阻塞状态")
}
