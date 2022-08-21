from cgi import test

from sqlalchemy import true


class TestClass:
    def __init__(self,test, strTest,Bigboolean) :
        #This is a list containing 
        self.test = test
        self.hexCheck = self.test[0]
        self.strTest = strTest
        self.Bigboolean = Bigboolean
    def getTestName(self):
        return self.test
    def getTestParams(self):
        return self.strTest
    def getTestResult(self):
        return self.Bigboolean

class CheckBitValue(TestClass):
    def executeTest(self):
        if(self.hexCheck[self.test[2]] == str(self.test[1])):
            print(self.hexCheck)
        
checkthis = CheckBitValue(["11110000",1,3],"1",true)
checkthis.executeTest()