'''
 *  $Id: Kernel.scons, 2014-08-05 19:32:25 DAMPE $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 24/07/2013
'''

import os

#-------------------------------------------------------------------
target='DmpKernel'

#-------------------------------------------------------------------
prefix='./Install'
if os.environ.has_key('DMPSWSYS'):
    prefix=os.environ['DMPSWSYS']
else:
    UsrPrefix=raw_input('Where to install DMPSW (press Enter to use default "%s"):'%prefix)
    #UsrPrefix=UsrPrefix.strip()
    if UsrPrefix:   prefix=UsrPrefix
prefix=os.path.abspath(prefix)
print "\n==>Installing DMPSW Framework into:\t%s\n" %prefix

#-------------------------------------------------------------------
env = Environment(ENV = os.environ)
env.ParseConfig("root-config --cflags --libs")
#env.Append(LIBS=['RooFitCore','RooFit'])
env.ParseConfig("python-config --include --libs")
env.Append(LIBS=['boost_python','boost_filesystem'])
includeDir='./include'
env.Prepend(CPPPATH=[includeDir])

# install share
#--------------------------------------------------------------------
Default(Command(prefix+'/lib/DMPSW.py','./script/DMPSW.py',Copy("$TARGET","$SOURCE")))
for tmp in os.listdir(includeDir):
    if ".h" in tmp:
        Default(Command(prefix+'/include/'+tmp,includeDir+'/'+tmp,Copy("$TARGET","$SOURCE")))
for tmp in os.listdir('./enum'):
    if ".h" in tmp:
        Default(Command(prefix+'/include/'+tmp,'./enum/'+tmp,Copy("$TARGET","$SOURCE")))
for tmp in os.listdir('./script'):
    if "dmp" in tmp:
        Default(Command(prefix+'/bin/'+tmp,'./script/'+tmp,Copy("$TARGET","$SOURCE")))

# main build
#--------------------------------------------------------------------
goal=env.SharedLibrary(target,Glob('./src/*.cc'))
Default(env.InstallAs(prefix+'/lib/lib'+target+".so",goal))

if env['PLATFORM'] == 'darwin':         # MacOs
    Default(env.InstallAs(prefix+'/lib/lib'+target+".dylib",goal))

