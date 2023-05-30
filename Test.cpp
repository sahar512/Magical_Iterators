#include"sources/MagicalContainer.hpp"
#include"doctest.h"
#include"iostream"
#include"stdexcept"
using namespace ariel; 
using namespace std;
TEST_CASE("test0 - cheack the MagicalContainer fun "){
    MagicalContainer magicContainer; 
    magicContainer.addElement(2); 
    magicContainer.addElement(6); 
    magicContainer.addElement(45); 
    CHECK(magicContainer.size()==3); 
    magicContainer.addElement(9); 
    magicContainer.removeElement(2); 
    CHECK(magicContainer.size()==3); 
    magicContainer.removeElement(45); 
    CHECK(magicContainer.size()==2); 
}
TEST_CASE("test1-AscendingIterator"){
    MagicalContainer container; 
    container.addElement(17); 
    container.addElement(2); 
    container.addElement(25); 
    // Test constructor and operator*
    MagicalContainer::AscendingIterator it(container);
    CHECK(*it == 2);  // The first element in ascending order is 2
    ++it; 
    CHECK(*it==17);  // The second element in ascending order is 17
    CHECK(container.size()==3);
    CHECK(it.begin()!=it.end());
    // Test copy assignment operator
    MagicalContainer::AscendingIterator copyIt(container);
    copyIt = it;
    CHECK(copyIt == it);  // The copy should have the same position as the original
    it=it.begin(); 
    ++it;
    ++it; 
    ++it;
    CHECK(*it==25); 
    // Test operator==
    MagicalContainer::AscendingIterator copy(container);
    CHECK(it == copy);  // Both iterators are at the same position
    ++copy;
    CHECK(it != copy);  // The iterators are now at different positions
    CHECK_THROWS(container.addElement(2)); //2 is already exist in the container
    CHECK_THROWS(container.removeElement(88)); //88 is not an elemnt in the container 
}
TEST_CASE("test2-SideCrossIterator"){
    //operator++ /operator*/begin / end 
    MagicalContainer CrossContainer; 
    CrossContainer.addElement(9);
    CrossContainer.addElement(4); 
    CrossContainer.addElement(2); 
    CrossContainer.addElement(7); 
    MagicalContainer::SideCrossIterator CrossItr(CrossContainer);
    auto element= CrossItr.begin(); 
    CHECK(*element==2);
    ++element; 
    CHECK(*element==9); 
    ++element;
    ++element; 
    CHECK(*element==7);  
    CHECK(element==CrossItr.end()); 
}
TEST_CASE("test3-PrimeIterator"){
    //operator++
    MagicalContainer PrimeContainer; 
    PrimeContainer.addElement(88); 
    PrimeContainer.addElement(13); 
    PrimeContainer.addElement(6); 
    PrimeContainer.addElement(1); 
    PrimeContainer.addElement(0); 
    PrimeContainer.addElement(5); 
    PrimeContainer.addElement(2); 
    CHECK(PrimeContainer.size()==7); 
    MagicalContainer::PrimeIterator PrimeItr (PrimeContainer);
    auto elemnteP=PrimeItr.begin(); 
    CHECK(*elemnteP==13);
    ++elemnteP; 
    CHECK(*elemnteP==5); 
    ++elemnteP; 
    CHECK(*elemnteP==2);
    CHECK(elemnteP == PrimeItr.end()); 
    CHECK(PrimeContainer.size()==7); 
}
TEST_CASE("test4- AscendingIterator operator == "){
    MagicalContainer Container; 
    Container.addElement(8); 
    Container.addElement(12); 
    MagicalContainer::AscendingIterator AscItr(Container);
    auto el0= AscItr.begin(); 
    auto el1= AscItr.end(); 
    CHECK(el0==el1); 
    CHECK(el1==el0); 
}
TEST_CASE("test5- SideCrossIterator operator == "){
    MagicalContainer Container; 
    Container.addElement(8); 
    Container.addElement(5); 
    MagicalContainer::SideCrossIterator CrossItr(Container);
    auto el0= CrossItr.begin(); 
    auto el1= CrossItr.end(); 
    CHECK(el0==el1); 
    CHECK(el1==el0); 
}
TEST_CASE("test6- PrimeIterator operator == "){
    MagicalContainer Container; 
    Container.addElement(13); 
    Container.addElement(1); 
    MagicalContainer::PrimeIterator PrimeItr(Container);
    auto el0= PrimeItr.begin(); 
    auto el1= PrimeItr.end(); 
    CHECK(el0==el1); 
    CHECK(el1==el0); 
    CHECK(Container.size()==2); 
    
}
TEST_CASE("test-7 class AscendingIterator"){
    MagicalContainer container0; 
    container0.addElement(1); 
    container0.addElement(9); 
    container0.addElement(2); 
    container0.addElement(8); 
    MagicalContainer container1; 
    container1.addElement(1); 
    container1.addElement(2); 
    container1.addElement(9); 
    container1.addElement(8);
    CHECK(container0.size()==container1.size()); 
    MagicalContainer::AscendingIterator AscItrator0(container0); 
    MagicalContainer::AscendingIterator AscItrator1(container0); 
    CHECK(AscItrator0.begin()==AscItrator0.end()); 
    CHECK(AscItrator0.begin()==AscItrator1.begin()); 
    CHECK(AscItrator0.end()==AscItrator1.begin());
    CHECK(AscItrator1.begin()==AscItrator1.end());
    CHECK(*AscItrator0.begin()==1); 
    CHECK(*AscItrator1.begin()==1); 
    CHECK(*AscItrator0.end()==8); 
    CHECK(*AscItrator1.end()==8); 
    CHECK((AscItrator0.operator==(AscItrator1))==true); 
    CHECK((AscItrator1.operator==(AscItrator0))==true);
    container0.addElement(0); 
    container0.addElement(3); 
    container0.addElement(77); 
    CHECK((AscItrator0.operator<(AscItrator1))==true); 
    CHECK((AscItrator0.operator>(AscItrator1))==true); 
    CHECK((AscItrator0.operator!=(AscItrator1))==true); 
    CHECK((AscItrator1.operator<(AscItrator0))==true); 
    CHECK((AscItrator1.operator>(AscItrator0))==true); 
    CHECK((AscItrator1.operator!=(AscItrator0))==true);

}
TEST_CASE("test-7 class AscendingIterator"){
    MagicalContainer container0; 
    container0.addElement(1); 
    container0.addElement(9); 
    container0.addElement(2); 
    container0.addElement(8); 
    MagicalContainer container1; 
    container1.addElement(1); 
    container1.addElement(2); 
    container1.addElement(9); 
    container1.addElement(8);
    CHECK(container0.size()==container1.size()); 
    MagicalContainer::SideCrossIterator CrossItrator0(container0); 
    MagicalContainer::SideCrossIterator CrossIrator1(container0); 
    CHECK(CrossItrator0.begin()==CrossItrator0.end()); 
    CHECK(CrossItrator0.begin()==CrossIrator1.begin()); 
    CHECK(CrossItrator0.end()==CrossIrator1.begin());
    CHECK(CrossIrator1.begin()==CrossIrator1.end());
    CHECK(*CrossItrator0.begin()==1); 
    CHECK(*CrossIrator1.begin()==1); 
    CHECK(*CrossItrator0.end()==8); 
    CHECK(*CrossIrator1.end()==8); 
    CHECK((CrossItrator0.operator==(CrossIrator1))==true); 
    CHECK((CrossIrator1.operator==(CrossItrator0))==true);
    container0.addElement(0); 
    container0.addElement(3); 
    container0.addElement(77); 
    CHECK((CrossItrator0.operator<(CrossIrator1))==true); 
    CHECK((CrossItrator0.operator>(CrossIrator1))==true); 
    CHECK((CrossItrator0.operator!=(CrossIrator1))==true); 
    CHECK((CrossIrator1.operator<(CrossIrator1))==true); 
    CHECK((CrossIrator1.operator>(CrossIrator1))==true); 
    CHECK((CrossIrator1.operator!=(CrossIrator1))==true);

}
TEST_CASE("test-7 class AscendingIterator"){
    MagicalContainer container0; 
    container0.addElement(1); 
    container0.addElement(9); 
    container0.addElement(2); 
    container0.addElement(8); 
    MagicalContainer container1; 
    container1.addElement(1); 
    container1.addElement(2); 
    container1.addElement(9); 
    container1.addElement(8);
    CHECK(container0.size()==container1.size()); 
    MagicalContainer::PrimeIterator PrimeItrator0(container0); 
    MagicalContainer::PrimeIterator PrimeIrator1(container0); 
    CHECK(PrimeItrator0.begin()==PrimeItrator0.end()); 
    CHECK(PrimeItrator0.begin()==PrimeIrator1.begin()); 
    CHECK(PrimeItrator0.end()==PrimeIrator1.begin());
    CHECK(PrimeIrator1.begin()==PrimeIrator1.end());
    CHECK(*PrimeItrator0.begin()==1); 
    CHECK(*PrimeIrator1.begin()==1); 
    CHECK(*PrimeItrator0.end()==8); 
    CHECK(*PrimeIrator1.end()==8); 
    CHECK((PrimeItrator0.operator==(PrimeIrator1))==true); 
    CHECK((PrimeIrator1.operator==(PrimeItrator0))==true);
    container0.addElement(0); 
    container0.addElement(3); 
    container0.addElement(77); 
    CHECK((PrimeItrator0.operator<(PrimeIrator1))==true); 
    CHECK((PrimeItrator0.operator>(PrimeIrator1))==true); 
    CHECK((PrimeItrator0.operator!=(PrimeIrator1))==true); 
    CHECK((PrimeIrator1.operator<(PrimeIrator1))==true); 
    CHECK((PrimeIrator1.operator>(PrimeIrator1))==true); 
    CHECK((PrimeIrator1.operator!=(PrimeIrator1))==true);

}
TEST_CASE("MAGICAL CONTAINER CHECK removeElement")
{
    MagicalContainer magicalContainer;
    magicalContainer.addElement(309);
    magicalContainer.addElement(314);
    magicalContainer.addElement(8);
    CHECK(magicalContainer.size()==3);
    magicalContainer.removeElement(631);
    CHECK(magicalContainer.size()==2);
    magicalContainer.addElement(-39);
    magicalContainer.addElement(0);
    CHECK(magicalContainer.size()==4);
    magicalContainer.addElement(-92);
    magicalContainer.removeElement(73);
    CHECK(magicalContainer.size()==4);
}




