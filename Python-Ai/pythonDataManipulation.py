from unittest import TestResult

from sqlalchemy import false

# 16  comnbibation of 0's and 1's.
# any digit within those 16 can be checked
# We pass in a 1 or 0, and wether the digit at that place matches(true,false) is returned
class TestCase():
    testName = ""
    testParams = [] #List of strings
    TestResult = false

    #Functions
    def getTestName(self,testName):
        self.testName  = testName
        return self.testName
    def getTestParams(testParams ):#check param list of stings
        self.testParams = testParams
        return self.testParams
    def executeTest(self):#fill
        return 0
    def setTestResult(self):#fill
        return 0
    def getTestResult(self,TestResult):
        return TestResult

class CheckBitValue(TestCase):
    def __init__(self):#Find how to inheret memebers from parent class in python
        self.testParams = self.getTestParams()

    #Functions
    def executeTest():
        #validate test params, 3 inputs, first is a string to be converted to hex>binary>string 
        #intialize testParams from input
        #check the index string[4] at postion input - 1
        #str compare between 0 or 1 (converted to a str)
        #return a true or false value if index from string[4] matches 
        #Get job
        
        return 0
    def printTestResult(self):
        print(self.testParams)
        return 0

#running
objectTest = CheckBitValue
#objectTest.getTestName("Test One")#Hex format ususally comes in 0x followed by hex
objectTest.getTestParams(["F0","1","5"]) #first args is hex, second is true or false check, 3rd is postions
objectTest.printTestResult()