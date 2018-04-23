 ///
 /// @file    RssReader.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-23 20:45:05
 ///

#include "tinyxml2.h"
//#include "Mylogger.h"
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <regex>

using std::cout;
using std::endl;
using std::string;

void test1(void)
{
	using namespace tinyxml2;
	
	XMLDocument doc;
	doc.LoadFile("coolshell.xml");

	XMLElement *proot = doc.FirstChildElement("rss");
	XMLElement *pchannel = proot->FirstChildElement("channel");
	XMLElement *pitem = pchannel->FirstChildElement("item");
	XMLElement *ptitle = pitem->FirstChildElement("title");
	XMLElement *plink = pitem->FirstChildElement("link");
	XMLElement *pdescription = pitem->FirstChildElement("description");
	XMLElement *pcontent = pitem->FirstChildElement("content:encoded");

	string title;
	string link;
	string description;
	string content;
	if(ptitle) title = string(ptitle->GetText());
	if(plink) link = string(plink->GetText());
	if(pdescription) description = string(pdescription->GetText());
	if(pcontent) content = string(pcontent->GetText());

	cout << "title:" << title << endl
		 << "link:" << link << endl
		 << "description:" << description << endl
		 << "content:" << content << endl;

	boost::regex re("<.+?>");//正则表达式：.代表任意字符,*代表一个或者多个字符长度,?代表非贪婪模式
	cout << endl;
	cout << boost::regex_replace(content, re, string()) << endl;
	int cnt = 1;

	string page =
		"<doc>\n"
		"	<docid>" + std::to_string(cnt) + "</docid>\n"
		"	   <title>" + title + "</title>\n"
		"	   <link>" + link + "</link>\n"
		"	   <content>" + content + "</content>\n"
		"</doc>\n";
}

void test2(void)
{
	string s1 = "I Don't Know";
	cout << boost::to_upper_copy(s1) << endl;
}

int main(void)
{
	test1();
	//test2();
	
	return 0;
}

