/***************************************************************************
                          DDLString.cc  -  description
                             -------------------
    begin                : Friday Nov. 21, 2003
    email                : case@ucdhep.ucdavis.edu
 ***************************************************************************/


namespace std{} using namespace std;

// Parser parts
#include "DetectorDescription/DDParser/interface/DDLString.h"
#include "DetectorDescription/DDParser/interface/DDLElementRegistry.h"

// other DD parts
#include "DetectorDescription/DDCore/interface/DDString.h"
#include "DetectorDescription/DDBase/interface/DDdebug.h"
#include "DetectorDescription/DDBase/interface/DDException.h"
#include "CLHEP/Units/SystemOfUnits.h"
#include "DetectorDescription/DDExprAlgo/interface/ExprEvalSingleton.h"

#include <map>
#include <string>

DDLString::DDLString()
{
}

DDLString::~DDLString()
{
}
 
void DDLString::preProcessElement (const string& name, const string& nmspace)
{
}

void DDLString::processElement (const string& name, const string& nmspace)
{
  DCOUT_V('P', "DDLString::processElement started");
  if (parent() == "ConstantsSection" || parent() == "DDDefinition")
    {
      // I do not like "newing" things without my control.  But this is
      // the only way I was able to get this to work.
      try {
	string * ts = new string((getAttributeSet().find("value"))->second);
	DDName ddn = getDDName(nmspace);
	DDString (ddn 
		  , ts
		  );
      } catch (DDException & e) {
	string msg(e.what());
        msg += "\nDDLString failed to create a DDString.";
	throwError(msg);
      }

      clear();
    }

  DCOUT_V('P', "DDLString::processElement completed");
}

