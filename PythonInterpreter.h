/********************************************************************************************************
*  File:        PythonInterpreter.h          	        | Copyright:: ##############################    *
*  Description: Contains the magic of translation       | BOX 1505                                      *
*  Rev:         Version 1                               | 125 25 ALVSJO                                 *
*  Created:     June 28, 2015                           | SWEDEN                                        *
*  Author:      Sumeet Kumar Sinha                      | tel int 530-601-8271                          *
*  Email:       sumeet.kumar507@gmail.com               |                                               *
*                                                                                                       *
*  The copyright to the computer program(s) herein is the property of #######################, ######.  *
*  The program(s) may be used and/or copied only with the written permission of Sumeet Kumar Sinha      *
*  or in accordance with the terms and conditions stipulated in the agreement/contract under which      *
*  the program(s) have been supplied.                                                                   *
********************************************************************************************************/
#ifndef PYTHONINTERPRETER_H
#define PYTHONINTERPRETER_H

#include <string>
#include <vector>
#include "GmshTranslator.h"
#include "Element.h"
#include "Node.h"

struct SelectionData{
	
   vector<Element> ElementList;
   vector<Node> NodeList;
};

using namespace::std;

class PythonInterpreter{

	public:
		PythonInterpreter();
		PythonInterpreter(const string& mshFile, int override = 1);
		void loadMshFile(const string& mshFile, int override = 1);
		void Convert(const string& GmssiCommand);
		string getEssiTag( const string& EssiTag);
		vector<Element> getPhysicalGroupElements(const int& n );
		vector<Node> getPhysicalGroupNodes(const int& n );
		vector<Element> getEntityGroupElements(const int& n );
		vector<Node> getEntityGroupNodes(const int& n );
		map<int,Node> getNodeMap();
		string getFilePath();
		bool copyFile(const string& Source, const string& Destination);
		string getFile();
		void ConvertFile(const string& mshFile,int override);
		void UpdateGmshFile();
		string MshFile;
		GmshTranslator Translator = GmshTranslator();
		SelectionData BoxSelection(string PhysEntyTag, double x1,double x2,double y1,double y2,double z1,double z2);
		SelectionData SphereSelection(string PhysEntyTag,double radius,double center_x,double center_y,double center_z);
		void CreatePhysicalGroup (string Name,vector<Node> NodeList, vector<Element> ElementList);


	private:

		// void ConvertFile(const string& mshFile,int override);
		// string MshFile;
		// GmshTranslator Translator = GmshTranslator();
		int setTypeIter(map<int,NodeElement>::iterator &TypeIter,const string& variable);
		string delSpaces(string str);

};

#endif //PYTHONINTERPRETER_H