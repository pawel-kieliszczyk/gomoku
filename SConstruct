compiler = ARGUMENTS.get('compiler', 'clang++')


env = Environment(CXX = compiler)
env.Append(CXXFLAGS = ['-Wall', '-Werror'])


SConscript('libraries/googletest/SConscript', variant_dir='bin/libraries/googletest', exports='env', duplicate=0)
SConscript('libraries/googlemock/SConscript', variant_dir='bin/libraries/googlemock', exports='env', duplicate=0)
SConscript('SConscript', variant_dir='bin', exports='env', duplicate=0)
