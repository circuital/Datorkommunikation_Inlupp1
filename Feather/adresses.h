#include "indexPage.h"
#include "textPage.h"

void IndexPage()
{
  String indexPage = index_page;
  server.send(200, "text/html", indexPage);
}

void TextPage()
{
  String textPage = text_page;
  server.send(200, "text/html", textPage);
}

void api_IndexPage()
{
  GetTempHumFromArduino();
}

void api_TextPage()
{
  GetTextFromWeb();
}
