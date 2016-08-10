import angr
import os

print "loading true"
b = angr.Project('/bin/true')
print '0x%x' % b.entry
print 'start at 0x%x, ending at 0x%x' % (b.loader.min_addr(), b.loader.max_addr())
print 'file name %s' % b.filename

print 'this is the CLE Loader object'
print b.loader

print 'this is a dictionary of the objects that are loaded as part of loading the binary (their types depend on the backend)'
print b.loader.shared_objects

print 'this is the memory space of the process after being loaded. It maps addresses to the byte at that address.'
print b.loader.memory[b.loader.min_addr()]

print 'this is the object for the main binary (its type depends on the backend)'
print b.loader.main_bin

print 'this retrieves the binary object which maps memory at the specified address'
print b.loader.addr_belongs_to_object(b.loader.max_addr())

print 'Get the address of the GOT slot for a symbol (in the main binary)'
print '0x%x' % b.loader.find_symbol_got_entry('__libc_start_main')

print 'this is a list of the names of libraries the program depend on. We obtain it'
print '*statically* by reading the DT_NEEDED field of the dynamic section of the Elf'
print 'binary.'
print b.loader.main_bin.deps

print 'this is a dict of the memory contents of *just* the main binary'
print b.loader.main_bin.memory

print 'this is a dict (name->ELFRelocation) of imports required by the libc which was loaded'
b.loader.shared_objects['libc.so.6'].imports

print 'this is a dict (name->ELFRelocation) of imports of the main binary, where addr is usually 0 (see the misc section below).'
print b.loader.main_bin.imports
