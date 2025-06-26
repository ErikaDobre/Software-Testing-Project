#include "pch.h" //header pentru a reduce timpul compilare 
#include "testul.h" //contine functiile f , sortAsc , sortDesc
#include <gtest/gtest.h>

//Simuleaza comportamentul modulelor apelate de modulul testat.
//Raspunde cu valori predefinite la apelurile facute de modulul testat.
//Este folosit pentru a testa modulul principal când modulele dependente nu sunt implementate sau sunt complexe.
int stub_f(int v[], int p1, int p2, int x) {
    return f(v, p1, p2, x); 
}

//Simuleaza apelurile catre modulul testat.
//Furnizeaza datele de intrare si evalueaza rezultatele.
//Este folosit pentru a testa un modul izolat, atunci când modulul care îl invoca nu este înca implementat.
void driver_sortAsc(int v[], int n) {
    sortAsc(v, n);
}


void driver_sortDesc(int v[], int n) {
    sortDesc(v, n);
}


void createSortedArray(int v[], int n) {
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }
}


void createReverseArray(int v[], int n) {
    for (int i = 0; i < n; ++i) {
        v[i] = n - i;
    }
}


TEST(BinarySearchTests, ValueExists)
{
    int v[] = { 1, 2, 3, 4, 5 };
    int pos = stub_f(v, 0, 4, 3);
    EXPECT_EQ(pos, 2);
}

TEST(BinarySearchTests, BoundaryConditions)
{
    int v[] = { 1,2,3,4,5 };
    ASSERT_EQ(f(v, 0, 4, 1), 0);
    ASSERT_EQ(f(v, 0, 4, 5), 4);
}


TEST(BinarySearchTests, ValueDoesNotExist)
{
    int v[] = { 1, 2, 3, 4, 5 };
    int pos = stub_f(v, 0, 4, 6);
    EXPECT_EQ(pos, -1);
}


TEST(BinarySearchTests, SearchFirstElement)
{
    int v[] = { 1, 2, 3, 4, 5 };
    int pos = stub_f(v, 0, 4, 1);
    EXPECT_EQ(pos, 0);
}

TEST(BinarySearchTests, SearchLastElement)
{
    int v[] = { 1, 2, 3, 4, 5 };
    int pos = stub_f(v, 0, 4, 5);
    EXPECT_EQ(pos, 4);
}


TEST(SortTests, SortAscending)
{
    int v[] = { 5, 4, 3, 2, 1 };
    driver_sortAsc(v, 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(v[i], i + 1);
    }
}

TEST(SortTests, SortDescending)
{
    int v[] = { 1, 2, 3, 4, 5 };
    driver_sortDesc(v, 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(v[i], 5 - i);
    }
}


TEST(SortTests, SortEmptyArray)
{
    int* v = nullptr;
    driver_sortAsc(v, 0);
    EXPECT_EQ(sizeof(v) / sizeof(v[0]), 0);
}

TEST(SortTests, SortSingleElement)
{
    int v[] = { 1 };
    driver_sortAsc(v, 1);
    EXPECT_EQ(v[0], 1);
}


TEST(SortTests, RandomArraySort)
{
    int v[] = { 3, 1, 4, 5, 2 };
    driver_sortAsc(v, 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(v[i], i + 1);
    }
}


TEST(IntegrationTests, SortAndSearch)
{
    int v[] = { 5, 4, 3, 2, 1 };
    driver_sortAsc(v, 5);
    int pos = stub_f(v, 0, 4, 3);
    EXPECT_EQ(pos, 2);
}


TEST(BinarySearchTests, SingleElementArray) {
    int v[] = { 3 };
    int pos = stub_f(v, 0, 0, 3);
    EXPECT_EQ(pos, 0);
}


TEST(BinarySearchTests, EmptySearchSpace) {
    int v[] = { 1, 2, 3, 4, 5 };
    int pos = stub_f(v, 1, 0, 3); 
    EXPECT_EQ(pos, -1);
}


TEST(SortTests, AlreadySortedArray) {
    int v[] = { 1, 2, 3, 4, 5 };
    driver_sortAsc(v, 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(v[i], i + 1);
    }
}


TEST(SortTests, ReverseSortedArray) {
    int v[] = { 5, 4, 3, 2, 1 };
    driver_sortAsc(v, 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(v[i], i + 1);
    }
}


TEST(SortTests, SingleElementArray) {
    int v[] = { 1 };
    driver_sortAsc(v, 1);
    EXPECT_EQ(v[0], 1);
}


TEST(SortTests, EmptyArray) {
    int* v = nullptr;
    driver_sortAsc(v, 0);
    EXPECT_EQ(v, nullptr);
}

TEST(BinarySearchTests, PositiveValueExists)
{
    int v[] = { 1,2,3,4,5 };
    int size = sizeof(v) / sizeof(v[0]);
    ASSERT_EQ(f(v, 0, size - 1, 3), 2);
}

TEST(BinarySearchTests, NegativeValueDoesNotExist)
{
    int v[] = { 1,2,3,4,5 };
    int size = sizeof(v) / sizeof(v[0]);
    ASSERT_EQ(f(v, 0, size - 1, 6), -1);
}

TEST(BinarySearchTests, AllElementsIdentical) {
    int v[] = { 3, 3, 3, 3, 3 };
    int pos = stub_f(v, 0, 4, 3);
    EXPECT_GE(pos, 0); 
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
