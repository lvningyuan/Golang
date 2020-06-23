package main

//USB  接口
type  USB  interface{
	start()// 接口定义一组具有共性的方法
	end()
}
// 鼠标
type Mouse struct {
	name string
}
//U盘
type FlashDisk struct {
	name string
}
//Mouse 的实现接口
func (m Mouse)start(){
	println("鼠标就绪，可以使用，点点点")
}

func (m Mouse)end(){
	println("鼠标结束工作 ，退出啦")
}

//U盘 实现接口
func(f FlashDisk)start(){
	println("闪迪准备就绪，可以开始传输数据了...")
}

func(f FlashDisk)end(){
	println("传输数据结束，U盘拔出")
}

//test测试函数 ： 普通函数，只进行测试（完美转发）
func testInterfae(usb USB){
	usb.start()
	usb.end()
}
func main(){
	m1 := Mouse{"鼠标"}
	println(m1.name)
	m1.start()
	m1.end()

	f1 :=FlashDisk{"闪迪"}
	println(f1.name)
	f1.start()
	f1.end()

	//testInterfae(m1)
	//testInterfae(f1)

}
