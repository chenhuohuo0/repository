import pandas
from selenium import webdriver
from time import sleep
driver = webdriver.Chrome()#加载驱动
driver.get('https://www.jd.com/')#打开网址
driver.maximize_window();sleep(1)
driver.find_element_by_xpath('//*[@id="key"]').send_keys('手机');sleep(2)#输入手机
driver.find_element_by_xpath('//*[@id="search"]/div/div[2]/button/i').click();sleep(2)#点击查找
price=[];details=[];comment=[];#store_mode=[];#label=[]
k=1
while k<=10:#页数太多运行时间太长，我们以十页为例
    sleep(3)
    list = driver.find_elements_by_xpath('//*[@id="J_goodsList"]/ul/li')
    for i in list:
        info=str(i.text).split('\n')
        price.append(info[0].strip())
        details.append(info[1].strip())
        comment.append(info[2].strip())
        #store_mode.append(info[3].strip())
        #label.append(info[4:]) 经测试，垃圾信息太多，我们在这里截断

        dictionary={
            '价格':price,
            '手机内容细节':details,
            '评论数':comment
            #'店铺模式':store_mode,
            #'其他标签':label
        }
    next_page=driver.find_element_by_xpath('//*[@id="J_bottomPage"]/span[1]/a[9]/em')
    if next_page.text=='下一页':
        print('第'+str(k)+'页内容已爬取')
        k+=1
        next_page.click()
    else :
        break
frame = pandas.DataFrame(dictionary)
frame.to_csv('京东手机信息.csv',index=False)
driver.quit()
