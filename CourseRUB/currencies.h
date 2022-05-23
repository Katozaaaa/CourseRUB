#ifndef CURR_H
#define CURR_H

#include <string>
#include "html.h"
#include "curl/curl.h"
#include "ParserDom.h"

class Currencies
{
public:
	static const size_t curr_size = 6;
	static const std::string curr_names[curr_size];
private:
	const HTML_CODE html;
	htmlcxx::HTML::ParserDom parser;
	const tree<htmlcxx::HTML::Node> dom = parser.parseTree(std::string(html.getHtml()));
	std::string curr_bids [curr_size];
public:
	Currencies();
	std::string getCurr(std::string) const;
};

#endif