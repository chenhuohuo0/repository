import requests
from lxml import etree
url='https://nba.hupu.com/stats/players'
headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 Edg/114.0.1823.67'
}
resp=requests.get(url,headers).text

#解析响应的数据
nos=etree.HTML(resp).xpath('//table[@class="players_table"]//tr/td[1]/text()')
names=etree.HTML(resp).xpath('//table[@class="players_table"]//tr/td[2]/a/text()')
teams=etree.HTML(resp).xpath('//table[@class="players_table"]//tr/td[3]/a/text()')
scores=etree.HTML(resp).xpath('//table[@class="players_table"]//tr/td[4]/text()')
names.insert(0,'球员')
teams.insert(0,'球队')
# print(nos)

# for i in range(len(nos)):
#     print(nos[i]+' '+names[i]+' '+teams[i]+' '+scores[i])
with open('nba_mumber.txt','w',encoding='utf-8')as f:
    for i in range(len(nos)):
        f.write(nos[i]+' '+names[i]+' '+teams[i]+' '+scores[i]+'\n')





