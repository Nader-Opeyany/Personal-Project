from cgi import test

from sqlalchemy import true


class TestClass:
    def __init__(self,test, strTest,Bigboolean) :
        self.test = test
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
        print(self.strTest)
        
checkthis = CheckBitValue(["1",1,1],"1",true)
checkthis.executeTest()