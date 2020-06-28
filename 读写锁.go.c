
读锁：

package main

import (
	"fmt"
	"sync"
	"time"
)

var wg sync.WaitGroup
var rwMutex *sync.RWMutex
func readMutex(i int){
	defer wg.Done()
	fmt.Println(i,"开始读...")
	rwMutex.RLock()
	fmt.Println(i, "正在读取数据...")

	time.Sleep(1 * time.Second)
	rwMutex.RUnlock()
	fmt.Println(i, "读结束....")
}
func main(){
	rwMutex = new(sync.RWMutex)
	go readMutex(1)
	go readMutex(2)

	wg.Add(2)
	wg.Wait()
	fmt.Println("main over...")
}






//写锁 



package main

import (
	"fmt"
	"sync"
	"time"
)

var rwMutex2 *sync.RWMutex
var wg2  sync.WaitGroup

func writeData(i int){
	defer wg2.Done()
	fmt.Println(i,"想来写...")
	rwMutex2.Lock()
	fmt.Println(i,"正在写入...")
	time.Sleep(1 * time.Second)
	fmt.Println(i,"写结束...")
	rwMutex2.Unlock()
}

func main(){
	rwMutex2 = new(sync.RWMutex)
	go writeData(1)
	go writeData(2)
	go writeData(3)


	wg2.Add(3)
	wg2.Wait()
	fmt.Println("main over...")
}
