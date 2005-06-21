#ifndef x_SaxToDom_h
#define x_SaxToDom_h

#include "xercesc/sax2/DefaultHandler.hpp"
#include "DetectorDescription/DDCore/interface/adjgraph.h"
#include "DetectorDescription/DDCore/interface/graphwalker.h"

#include "DetectorDescription/DDRegressionTest/src/TinyDom.h"

#include <string>
#include <map>
#include <vector>
namespace xercesc_2_3 {} using namespace xercesc_2_3;

class AttributeList;

class SaxToDom : public DefaultHandler
{

public:
  SaxToDom();
  ~SaxToDom();
  void startElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname, const Attributes& attrs);
  //void startElement(const XMLCh* const name, AttributeList& attributes);
  void endElement(const XMLCh* const uri, 
                            const XMLCh* const name, 
			       const XMLCh* const qname);
  const TinyDom & dom() const;

  // errors
  void error(const SAXParseException& e);
  
private:
  std::vector<NodeName> parent_;
  TinyDom dom_; 
};

#endif
