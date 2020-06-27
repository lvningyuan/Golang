package main

import (
	"fmt"
	"math/rand"
	"runtime"
	"time"
)

func printNum() {
	for i := 1; i <= 1000; i++ {
		fmt.Println(i)
	}
}
func printChar() {
	for i := 1; i <= 1000; i++ {
		fmt.Printf("%c, %d\n", 'A', i)
	}
}

func child() {
	n := runtime.GOMAXPROCS(runtime.NumCPU())
	fmt.Println("GoMax CPU is :", n)
}

var count int = 100

func fun1(name string) {
	rand.Seed(time.Now().UnixNano())
	for true {
		if count > 0 {
			//模拟 业务处理耗费时间
			time.Sleep(time.Duration(rand.Intn(100)) * time.Millisecond)
			fmt.Println(name, ": 出票成功...  当前余票: %d", count-1)
			count--
		} else {
			fmt.Println(name, ": Sorry, 暂无余票...")
			break
		}
	}
}

func SellTicket() {
	go fun1("窗口1")
	go fun1("窗口2")
	go fun1("窗口3")
	go fun1("窗口4")
}

func main() {
	SellTicket()
	time.Sleep(3 * time.Second)
}

//一个Goroutine打印数字，  另一个过Goroutine打印z字母：
//go printNum()
/*
	for i:=1; i<1000; i++{
		fmt.Printf("%c   ,%d\n",'A',i)
	}
*/

/*
	go printChar()
	time.Sleep(1 * time.Second)
	fmt.Println("main over...")
*/

/*
	fmt.Println("goroot目录：", runtime.GOROOT())
	fmt.Println("当前操作系统：",runtime.GOOS)//darwin, mac系统
	fmt.Println("逻辑CPU的数量-->",runtime.NumCPU())//
	//注意最在程序运行之前就设置好， 可以写在init函数里

	n := runtime.GOMAXPROCS(runtime.NumCPU())//设置逻辑CPU的数量，返回值是上一次设置的数量


	fmt.Println("逻辑CPU的最大数量为：",n)// 说明最大只能为4
*/

//goSched  让当前GoRoutine让出CPU的时间片
//一个goroutine
/*
	go func (){
		for i:=0; i<4; i++ {
			fmt.Println("goroutine...")
		}
	}()
	//main  goroutine
	for i :=0; i<4; i++{
		runtime.Gosched()//主goroutine抢到CPU时，让出时间片
		fmt.Println("main。。。。")
	}

	/*

	go child()
	go func (){
		for i:=0; i<4; i++{
			fmt.Println("goroutine...")
		}
	}()
	for i :=0; i<4; i++{
		runtime.Gosched()
		fmt.Println("main....")
	}



*/

/*
	go func(){
		fmt.Println("go 开始...")
		fun()
		fmt.Println("go程序结束")
	}()
	time.Sleep(3 * time.Second)//主 goroutine睡3秒
}
func fun(){
	fmt.Println("进入fun函数...")
	defer fmt.Println("defer...")
	//return // 只是结束当前fun函数
	runtime.Goexit() // 完全退出当前的goroutine
	fmt.Println("退出fun函数...")

*/
/*
//临街资源 a
	a :=1
	go func(){
		a =2
		fmt.Println(a)
	}()
	a = 3// main goroutine  a =3  ,接着子goroutine 中 设置a =2,因此 最终a=2
	time.Sleep(1 * time.Second)
	fmt.Println(a)
}
*/
