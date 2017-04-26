compiler = ARGUMENTS.get('compiler', 'clang++')


env = Environment(CXX = compiler)
env.Append(CXXFLAGS = ['-std=c++14', '-Wall', '-Werror'])


SConscript('Libraries/googletest/SConscript', variant_dir='Bin/Libraries/googletest', exports='env', duplicate=0)
SConscript('Libraries/googlemock/SConscript', variant_dir='Bin/Libraries/googlemock', exports='env', duplicate=0)
SConscript('SConscript', variant_dir='Bin', exports='env', duplicate=0)
