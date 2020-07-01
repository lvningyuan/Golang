package main

import "fmt"


func main(){
	/*
	创建一个通道
	 */
	var a chan int  //创建一个int 类型的从通道 a
	fmt.Printf("a type is %T，%v\n",a,a)
	//刚创建的通道是nil的 ， 不能使用
	if a ==nil{
		fmt.Println("channel a is nil , can't be used...")
		a = make(chan int)
		fmt.Println(a)// 现在发现通道是一个引用类型数据
	}
	test1(a)

}

//通道传地址
func  test1(ch chan int){
	fmt.Printf("类型：%T, %v\n",ch,ch)
}









package main

import "fmt"

func main(){
	var ch1 chan bool
	ch1 = make(chan bool)
	go func(){
		for i:=0; i<4; i++{
			fmt.Printf("子goroutine 中 i-> %d\n",i)
		}
		// 循环结束后 ，向通道中写入数据
		ch1 <- true// 该操作可以解除读操作的阻塞
		fmt.Println("子goroutine 结束...")
	}()

	data := <- ch1//先阻塞， 等子gorooutine写入数据后， 该读操作随机解除阻塞
	fmt.Println("main goroutine read data :",data)
	fmt.Println("main over...")
}






// 遍历 读取数据 
package main

import (
	"fmt"
	"time"
)

func main(){
	/*
		关闭通道
	*/
	ch2 := make(chan int)
	go func(){
		for i:=0; i<10; i++ {
			ch2 <- i
			fmt.Println("子 goroutine写入数据->",i)
		}
		fmt.Println("子goroutine 结束...")
		close(ch2)
	}()
	for data2:= range ch2{
		time.Sleep(2 * time.Millisecond)// 保证 数据被写入通道
		//data2, ok := <-ch2
		//if ok != true {
		//	fmt.Println("读取通道数据结束...")
		//	break
		fmt.Println("main get data->",data2)
		fmt.Println("main goroutine read data ->", data2)
	}
	fmt.Println("main goroutine over...")
}
