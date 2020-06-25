package main

import (
	"fmt"
	"io"
	"io/ioutil"
	"os"
)

func CopyFile1(srcFile,destFile string)(int64,error){
	file1,err := os.Open(srcFile)
	if err != nil{
		return 0, err
	}

	//否则打开srcFile文件成功
	file2,err := os.OpenFile(destFile,os.O_WRONLY|os.O_CREATE|os.O_APPEND,os.ModePerm )
	if err != nil{
		return 0,err
	}
	defer file2.Close()
	defer file1.Close()
	return io.Copy(file2,file1)
}

func CopyFile2(srcFile, destFile string)(int, error){
	//打开文件
	//内存（栈）中会自动建立一个缓冲区 ；  因此不适合较大文件的复制
	bs,err := ioutil.ReadFile(srcFile)

	if err != nil{
		return 0,err
	}

	err = ioutil.WriteFile(destFile,bs,os.ModePerm)//或者写成0777一样的
	if  err != nil{
		return 0, err
	}
	return len(bs),nil
}

func main(){

	//创建绝对路径文件
	//os.Create 文件不存在时 会创建文件, 文件存在时 会将其截断（置空）

	file1,err := os.Create("/Users/mac/go/file_test/1.txt")
	if err != nil{
		fmt.Println(err)
	}
	fmt.Println(file1)// 打印地址

	//创建绝对路径下的文件
	FileName2 := "2.txt"
	file2, err:= os.Create(FileName2)
	if err != nil{
		fmt.Println(err)
	}
	fmt.Println(file2)

	FileName3 := "aa.txt"
	file3,err := os.Open(FileName3)// Open  只读方式打开文件
	if err != nil{
		fmt.Println(err)
	}
	fmt.Println(file3)

	//os.ModePerm 默认是 0777
	//目标文件， 打开方式， 目标文件不存在时创建文件的权限
	file4 ,err := os.OpenFile(FileName3, os.O_RDWR, os.ModePerm)
	if err != nil{
		fmt.Println(err)
		return
	}
	fmt.Println(file4)

	//关闭文件
	file4.Close()
	//删除文件
	//os.Remove(" dest file's absolute path")
	 err1 :=os.Remove("/Users/mac/go/file_test/1.txt")
	 if err1 != nil{
	 	fmt.Println(err1)
	 }
	 fmt.Println("删除目录成功")

	 //Remove 删除目录的前提是 ： 该目录必须是一个空目录才可以删除
	 //RemoveALl()  递归删除一个目录下的所有文件和子目录
	 err2 := os.RemoveAll(" dest  path")
	 if err2 != nil{
	 	fmt.Println(err2)
	 }
	 fmt.Println(err2)

	FileName4 := "path"
	file, err :=os.Open(FileName4) //Read 方式打开文件
	if err != nil{
		fmt.Println(err)
	}
	//关闭文件
	defer file.Close()

	DS := make([]byte,4,4)// 用切片接收数据
	n ,err := file.Read(DS)  // n:  读取到的长度
	if err != nil{
		fmt.Println(err)
	}
	fmt.Println(n)// 打印读取的数据
	fmt.Println(string(DS))

	//如果数据读完了｜｜ 或者文件为空：  那么 err  == io.EOF  n==0


	//写入数据 ：  每次 会从文件的开头写入， 如果文件中已有数据，新写入的将会覆盖原有的数据
	//想要追加写的话 需要在打开文件描述苻的时候指定 os.O_APPEND
	FileName5 := "path5"
	file, err = os.OpenFile(FileName5, os.O_RDWR|os.O_APPEND, os.ModePerm)
	if err != nil{
		fmt.Println(err)
	}
	//否则 ，打开文件成功
	bs :=[]byte{'A','B','C','D'}
	//将切片文件写入
	n,err3 := file.Write(bs)
	if err3 != nil{
		fmt.Println(err3)
	}
	fmt.Println("写入了",n,"个字节数据")

	//写出数据的一部分：
	file.Write(bs[:3])//写入切片中的前三个

	//直接写出字符串
	n2,err :=file.WriteString("hello world")
	println(n2," ",err)

	n3, err :=file.Write([]byte("today"))//可以将 字符床做成一个切片
	println(n3," ",err)



}

