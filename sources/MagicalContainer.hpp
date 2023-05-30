#pragma once
#include <vector>
using namespace std;

namespace ariel {
    class MagicalContainer {
        private:
        vector<int> MagicIterator;
        //vector<int> AscendingIterator;
       // vector<int> PrimeIterator;

    public:
        MagicalContainer() {}
        void addElement(int element) {}
        void removeElement(int element) {}
        int size() const {
            return 1;
        }
        class AscendingIterator {
            private:
            MagicalContainer& container;
            size_t currentIndex;

            public:
            AscendingIterator(MagicalContainer& Magic_C): container(Magic_C), currentIndex(0) {}
            ~AscendingIterator() {}
            //AscendingIterator(const AscendingIterator& other) {} 
            void operator=(const AscendingIterator& other) {}


            int operator*() const {
                return container.MagicIterator[currentIndex];
            }

            AscendingIterator& operator++() {
                ++currentIndex;
                return *this;
            }

            bool operator==(const AscendingIterator& other) const {
                //return currentIndex == other.currentIndex;
                return false; 
            }

            bool operator!=(const AscendingIterator& other) const {
                // return !(*this == other);
                return false; 
            }

            bool operator<(const AscendingIterator& other) const {
                return false;
            }
            bool operator>(const AscendingIterator& other) const {
                return false;
            }
            int operator*()  {
                return 0;
            }
            AscendingIterator operator++() const {
                return *this;
            }

            AscendingIterator &begin() {
                return *this;
            }

            AscendingIterator &end() {
                // AscendingIterator it = *this;
                //it.currentIndex = container.MagicIterator.size();
                return *this;
            }
        };
        class SideCrossIterator {
            private:
            MagicalContainer& container;
            size_t currentIndex;
            public:
            SideCrossIterator(MagicalContainer& Magic_C): container(Magic_C), currentIndex(0) {}

            ~SideCrossIterator() {}
            //SideCrossIterator(const SideCrossIterator& other) {}
            void operator=(const SideCrossIterator& other) {}
            bool operator==(const SideCrossIterator& other) const {
                return false;
            }
            bool operator!=(const SideCrossIterator& other) const {
                return false;
            }
            bool operator<(const SideCrossIterator& other) const {
                return false;
            }
            bool operator>(const SideCrossIterator& other) const {
                return false;
            }
            int operator*() const {
                return 0;
            }
            SideCrossIterator operator++() const {
                return *this;
            }
            SideCrossIterator &begin()  {
                return *this;
            }
            SideCrossIterator &end()  {
                return *this;
            }
        };

        class PrimeIterator {
            private:
            MagicalContainer& container;
            size_t currentIndex;
            public:
            PrimeIterator(MagicalContainer& Magic_C):container(Magic_C), currentIndex(0) {}
            ~PrimeIterator() {}
            //PrimeIterator(const PrimeIterator& other) {}
            void operator=(const PrimeIterator& other) {}
            bool operator==(const PrimeIterator& other) const {
                return false;
            }
            bool operator!=(const PrimeIterator& other) const {
                return false;
            }
            bool operator<(const PrimeIterator& other) const {
                return false ;
            }
            bool operator>(const PrimeIterator& other) const {
                return false;
            }
            int operator*(){
                return 0;
            }
            PrimeIterator operator++() const {
                return *this;
            }
            PrimeIterator begin() const {
                return *this;
            }
            PrimeIterator end() const {
                return *this;
            }
        };
    };
}
