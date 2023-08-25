import pandas
from selenium import webdriver
from time import sleep
driver = webdriver.Chrome()#加载驱动
driver.get('https://www.maoyan.com/')#打开网址
driver.maximize_window()#放大页面
sleep(2)
driver.find_element_by_xpath('/html/body/div[1]/div/div[2]/div[5]/a').click()#定位到榜单并点击
sleep(2)
driver.find_element_by_xpath('/html/body/div[3]/ul/li[5]/a').click()#定位到top100榜并点击
sleep(2)
ranking=[];movie=[];actor=[];released_day=[];score=[];
while True:
    sleep(2)
    list=driver.find_elements_by_xpath('//*[@id="app"]/div/div/div[1]/dl/dd')
    for i in list:
        info = str(i.text).split('\n')
        ranking.append(info[0].strip())
        movie.append(info[1].strip())
        actor.append(info[2].strip())
        released_day.append(info[3].strip())
        score.append(info[4].strip())
        x={
                  '电影排名':ranking,'电影名字':movie,'电影主演':actor,'上映时间':released_day,'电影评分':score
              }
    last = driver.find_element_by_xpath('//*[@id="app"]/div/div/div[2]/ul/li[last()]/a')
    if last.text == '下一页': last.click()
    else:break
frame = pandas.DataFrame(x)
frame.to_csv('猫眼电影TOP100排行榜.csv', index=False)
driver.quit()