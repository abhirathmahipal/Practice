class FooClass(object):
    '''Doc String'''
    version = 0.1 # is shared among the functions of FooClass
    def __init__(self, nm='John Doe'):
        '''constructor'''
        self.name = nm
        print "created a class instance for ", nm
        
    def showname(self):
        print 'Your name is', self.name
        print 'My Name is', self.__class__.__name__    
        
    def showver(self):
        print self.version    
        
    def addMe2Me(self, x):
        return x + x

foo1 = FooClass()
foo2 = FooClass('Jane Smith')
foo1.showname()
foo2.showname()