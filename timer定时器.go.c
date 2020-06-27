package main

import (
	"fmt"
	"time"
)

func main(){
	/*
		1  func NewTimer(d Duration)创建一个计时器， d时间以后触发
	*/
	timer := time.NewTimer(3 * time.Second) //timer是一个time.Timer指针
	fmt.Printf("timer type is %T\n",timer)
	fmt.Println(time.Now())

	//阻塞三秒钟 触发 计时器
	ch2 := timer.C //C 是一个通道
	fmt.Println(<-ch2)// 读取 ch2内的数据 ： 读取的是3秒之后的时间

	fmt.Println()

	ch4 := time.After(3 * time.Second)//After 作用和Newtimer一样，但返回一个 通道
	fmt.Println(time.Now())
	fmt.Println(<-ch4)
}

