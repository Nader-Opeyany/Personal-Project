from mimetypes import init


class Polygon():
    def __init__(self,sides) -> None:
        self.sides = sides

    def displayInfo(self):
        print("A polygon is a 2 Dimensional shape with straight lines")
    
    def getPerimter(self):
        perimeter = sum(self.sides)
        return perimeter
    
class Triangle(Polygon):
    def displayInfo(self):
        print("A triagnle is a ploygon with 3 edges")

class Quadrilateral(Polygon):
    def displayInfo(self):
        print("A quadrilateral is a polyon with 4 edges")

#Test for perimeter
triangle = Triangle([5,6,7])
perimeter = triangle.getPerimter()
print("Preimeter is ",perimeter)
triangle.displayInfo()

quad = Quadrilateral([1,2,3,4])
quadOut = quad.getPerimter()
print("The Perimeter for quad is: ",quadOut)