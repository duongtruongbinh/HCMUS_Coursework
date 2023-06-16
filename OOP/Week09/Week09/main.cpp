#include "CFile.h"
#include "CFolder.h"
using namespace std;
int main() {
	CFolder C("C"); // (1)
	CFolder System("System");
	CFolder Windows("Windows");
	CFile a_txt("a.txt", 123); // (2)
	CFile b_doc("b.doc", 456);
	System.add(&a_txt); // (3)
	Windows.add(&b_doc);
	C.add(&System); // (4)
	C.add(&Windows);
	cout << "Content of folder C ->" << endl;
	bool isPrintHiddenItems = false;
	C.print(isPrintHiddenItems); // print hidden items or not? 1/0 (5)
	CItem* p = C.removeByName("System"); // (6)
	cout << "Content of folder C afer removing folder System ->" << endl;
	C.print(false);
	p = C.findByName("b.doc"); // (7)
	if (p != NULL) {
		cout << "b.doc is found in folder C" << endl;
	}
	else {
		cout << "b.doc is not found" << endl;
	}
	p = C.findByName("a.txt");
	if (p != NULL) {
		cout << "a.txt is found" << endl;
	}
	else {
		cout << "a.txt is not found" << endl;
	}
	p = C.findByName("Windows"); // (8)
	bool isHidden;
	bool isAlsoApplyToChildren;
	if (p != NULL) {
		cout << "Folder Windows is folder. Content of folder Windows ->" << endl;
		isHidden = true; isAlsoApplyToChildren = false;
		// set HIDDEN to folder p and do not change hidden attributes of its sub-items
		p->setHidden(isHidden, isAlsoApplyToChildren); // (9)
		p->print(false);

		// set HIDDEN to folder p and all its items
		isHidden = true; isAlsoApplyToChildren = true;
		p->setHidden(isHidden, isAlsoApplyToChildren); // (10)
		p->print(false);
	}
	else {
		cout << "Folder Windows is not found" << endl;
	}
	return 0;
}