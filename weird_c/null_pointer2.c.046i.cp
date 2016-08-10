
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  main:

 Propagating constants:

Not considering main for cloning; -fipa-cp-clone disabled.

overall_size: 4, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: main/15:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

main/15 (main) @0x7fe19fe81128
  Type: function
  Visibility: public
  References: 
  Referring: 
  Availability: available
  Function flags: analyzed body finalized only_called_at_startup
  Called by: 
  Calls: 
main ()
{
  <bb 2>:
  MEM[(int *)0B] = 1;
  return 0;

}



;; Function main (main, funcdef_no=15, decl_uid=2413, cgraph_uid=15) (executed once)

Modification phase of node main/15
main ()
{
  <bb 2>:
  MEM[(int *)0B] = 1;
  return 0;

}


