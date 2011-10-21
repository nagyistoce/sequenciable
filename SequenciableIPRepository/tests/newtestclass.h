/*
 * File:   newtestclass.h
 * Author: claudio
 *
 * Created on Sep 23, 2011, 1:56:01 PM
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testActionPerformed);
    CPPUNIT_TEST(test2);
    CPPUNIT_TEST(test3);
    CPPUNIT_TEST(test4);
    CPPUNIT_TEST(test5);
    CPPUNIT_TEST(test6);
    CPPUNIT_TEST(test7);
    CPPUNIT_TEST(test8);
    
    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testActionPerformed();
    void test2();
    void test3();
    void test4();
    void test5();
    void test6();
    void test7();
    void test8();
    
    IplImage *redImage;
    IplImage *greenImage;
    IplImage *blueImage;
    IplImage *yellowImage;
    IplImage *cianImage;
    IplImage *magentaImage;
    IplImage *blackImage;
    IplImage *whiteImage;
};

#endif	/* NEWTESTCLASS_H */

