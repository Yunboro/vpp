// (c) KJR
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <sstream>

#include "produktmitpreishistory.h"
#include "hochlager.h"
#include "a04.h"

#include "produkt.h"
#include "iprodukt.h"

using namespace testing;

TEST(IProduktAndProdukt, VirtualMethoden)
{
  Produkt p1{"PiPico", 4.99};
  IProdukt* ip = &p1;
  const char* pname = "PiPico";
  EXPECT_STREQ(pname, ip->getName().c_str());
  EXPECT_DOUBLE_EQ(4.99, ip->getPreis());
  ip->setPreis(5.12);
  EXPECT_DOUBLE_EQ(5.12, ip->getPreis());
  const char* sout = "Name: PiPico    , Preis:      5.12";
  std::ostringstream oss;
  ip->output(oss);
  EXPECT_STREQ(sout, oss.str().c_str());
  std::ostringstream oss2;
  oss2 << *ip;
  EXPECT_STREQ(sout, oss2.str().c_str());
}

TEST(Produkt, MethodenAndConst)
{
   Produkt p1{"PiPico", 4.99};
   p1.setName("Trafo");
   const char* pname = "Trafo";
   EXPECT_STREQ(pname, p1.getName().c_str());
   const Produkt& rp = p1;
   EXPECT_STREQ(pname, rp.getName().c_str());
   EXPECT_DOUBLE_EQ(4.99, rp.getPreis());
   const char* sout = "Name: Trafo     , Preis:      4.99";
   std::ostringstream oss;
   rp.output(oss);
   EXPECT_STREQ(sout, oss.str().c_str());
}
/*
TEST(ProduktMitPreisHistory, KonstruktorAndMethoden)
{
  ProduktMitPreisHistory pph{"Raspi", 23.78};
  Produkt& rp = pph;
  const char* pname = "Raspi";
  EXPECT_STREQ(pname, rp.getName().c_str());
  EXPECT_DOUBLE_EQ(23.78, rp.getPreis());
  const char* sout = "Name: Raspi     , Preis:     23.78"
                     "\nPreis History:\n";
  std::ostringstream oss;
  rp.output(oss);
  EXPECT_STREQ(sout, oss.str().c_str());
}

TEST(ProduktMitPreisHistory, HistoryAndBigThree){
  ProduktMitPreisHistory pph{"Raspi", 23.78};
  pph.setPreis(23.77);
  pph.setPreis(23.60);
  pph.setPreis(23.40);
  const char* sout = "Name: Raspi     , Preis:     23.40"
                     "\nPreis History:\n"
                     "23.78\n"
                     "23.77\n"
                     "23.60\n";
  std::ostringstream oss;
  pph.output(oss);
  EXPECT_STREQ(sout, oss.str().c_str());
  ProduktMitPreisHistory pph2{pph};
  pph.setPreis(23.30);
  pph.setPreis(23.20);
  pph.setPreis(23.10);
  std::ostringstream oss2;
  pph2.output(oss2);
  EXPECT_STREQ(sout, oss2.str().c_str());
  pph2 = pph;
  const char* sout2 = "Name: Raspi     , Preis:     23.10"
                      "\nPreis History:\n"
                      "23.77\n"
                      "23.60\n"
                      "23.40\n"
                      "23.30\n"
                      "23.20\n";
  std::ostringstream oss3;
  pph2.output(oss3);
  EXPECT_STREQ(sout2, oss3.str().c_str());
  pph2.setPreis(22.99);
  std::ostringstream oss4;
  pph.output(oss4);
  EXPECT_STREQ(sout2, oss4.str().c_str());
}

TEST(ProduktMitPreisHistory, CounterConstructorsAndDestructor){
  EXPECT_TRUE(0 == ProduktMitPreisHistory::getCounter());
  Produkt* pp = new ProduktMitPreisHistory{"Raspi", 23.78};
  EXPECT_DOUBLE_EQ(23.78, pp->getPreis());
  EXPECT_TRUE(1 == ProduktMitPreisHistory::getCounter());
  delete pp;
  EXPECT_TRUE(0 == ProduktMitPreisHistory::getCounter());
  ProduktMitPreisHistory pph1{"Raspi", 23.78};
  EXPECT_TRUE(1 == ProduktMitPreisHistory::getCounter());
  ProduktMitPreisHistory pph2 = pph1;
  EXPECT_TRUE(2 == ProduktMitPreisHistory::getCounter());
  pph2.setPreis(25.49);
  EXPECT_DOUBLE_EQ(23.78, pph1.getPreis());
  EXPECT_DOUBLE_EQ(25.49, pph2.getPreis());
  pph2 = pph1;
  EXPECT_DOUBLE_EQ(23.78, pph1.getPreis());
  EXPECT_DOUBLE_EQ(23.78, pph2.getPreis());
  EXPECT_TRUE(2 == ProduktMitPreisHistory::getCounter());
}

TEST(Kiste, Members){
  Kiste<int> ki{42, nullptr};
  EXPECT_TRUE(ki.inhalt == 42);
  EXPECT_TRUE(ki.next == nullptr);
}

TEST(HochLager, Constructor){
  Produkt p1{"Trafo", 17.89};
  HochLager<Produkt> lager{};
  EXPECT_TRUE(lager.getAnzahl(p1) == 0);
  EXPECT_DOUBLE_EQ(lager.getMaxPreis(), 0.0);
}

TEST(HochLager, Members){
  Produkt p1{"Trafo", 17.89};
  Produkt p2{"Raspi", 49.56};
  Produkt p4{"PiPico", 4.99};

  ProduktMitPreisHistory pph{"Lampe", 23.78};

  HochLager<Produkt> lager{};
  lager+= p1;
  EXPECT_TRUE(lager.getAnzahl(p1) == 1);
  EXPECT_DOUBLE_EQ(lager.getMaxPreis(), 17.89);
  const char* sout1 = "Name: Trafo     , Preis:     17.89 :   1\n";
  std::ostringstream oss1;
  lager.printInventarAufsteigendNachPreis(oss1);
  EXPECT_STREQ(sout1, oss1.str().c_str());
  const char* sout2 = "Name: PiPico    , Preis:      4.99 :   2\n"
                      "Name: Trafo     , Preis:     17.89 :   5\n"
                      "Name: Lampe     , Preis:     23.78 :   1\n"
                      "Name: Raspi     , Preis:     49.56 :   3\n";

  lager+= p1;
  lager+= p1;
  lager+= p1;
  lager+= p1;
  lager+= p2;
  lager+= p2;
  lager+= p2;
  lager += p4;
  lager += p4;
  lager += pph;
  std::ostringstream oss2;
  lager.printInventarAufsteigendNachPreis(oss2);
  EXPECT_STREQ(sout2, oss2.str().c_str());
  EXPECT_DOUBLE_EQ(lager.getMaxPreis(), 49.56);
  Produkt perg1 = lager -= p4;
  EXPECT_STREQ(perg1.getName().c_str(), p4.getName().c_str());
  Produkt perg2 = (lager -= pph);
  EXPECT_STREQ(perg2.getName().c_str(), pph.getName().c_str());
  const char* sout3 = "Name: PiPico    , Preis:      4.99 :   1\n"
                      "Name: Trafo     , Preis:     17.89 :   5\n"
                      "Name: Raspi     , Preis:     49.56 :   3\n";
  std::ostringstream oss3;
  lager.printInventarAufsteigendNachPreis(oss3);
  EXPECT_STREQ(sout3, oss3.str().c_str());
  perg2 = (lager -= p2);
  EXPECT_STREQ(perg2.getName().c_str(), p2.getName().c_str());
  EXPECT_TRUE(lager.getAnzahl(p2) == 2);
  perg2 = (lager -= p2);
  EXPECT_STREQ(perg2.getName().c_str(), p2.getName().c_str());
  EXPECT_TRUE(lager.getAnzahl(p2) == 1);
  perg2 = (lager -= p2);
  EXPECT_STREQ(perg2.getName().c_str(), p2.getName().c_str());
  EXPECT_TRUE(lager.getAnzahl(p2) == 0);
  EXPECT_DOUBLE_EQ(lager.getMaxPreis(), 17.89);
}

TEST(HochLager, Exceptions){
  Produkt p1{"Trafo", 17.89};
  Produkt p2{"Raspi", 49.56};  
  HochLager<Produkt> lager{};  
  ASSERT_THROW((void)(lager -= p1), std::runtime_error);
  try {
    (void)(lager -= p1);
    FAIL();
  } catch (const std::exception& e) {
    EXPECT_STREQ(e.what(), "Inhalt kann nicht geloescht werden");
  } catch(...){
      FAIL();  
  }
  lager += p1;
  lager += p2;
  lager += p1;
  lager -= p2;
  ASSERT_THROW((void)(lager -= p2), std::runtime_error);
  try {
      (void)(lager -= p2);
      FAIL();
  } catch (const std::exception& e) {
      EXPECT_STREQ(e.what(), "Inhalt kann nicht geloescht werden");
  } catch(...){
      FAIL();  
  }
}

TEST(Aufgabe4, CollatzGenerator){
  Collatz c10{10};
  EXPECT_TRUE(c10() == 10);
  EXPECT_TRUE(c10() == 5);
  EXPECT_TRUE(c10() == 16);
  EXPECT_TRUE(c10() == 8);
  EXPECT_TRUE(c10() == 4);
  EXPECT_TRUE(c10() == 2);
  EXPECT_TRUE(c10() == 1);
  EXPECT_TRUE(c10() == 4);
}

TEST(Aufgabe4, PraedikatPCollatz){
  PCollatz pcol{};
  EXPECT_TRUE(pcol(42));
  EXPECT_FALSE(pcol(1));
}

TEST(Aufgabe4, LaengeFunktor){
  Collatz c100{100};
  PCollatz pcollatz{};
  EXPECT_TRUE(laenge(c100, pcollatz) == 25);
}

TEST(Aufgabe4, LaengeFunctional){
  Collatz c100{100};
  TFC fc = [](int a){return a != 1;};
  EXPECT_TRUE(laenge(c100, fc) == 25);
}

TEST(Aufgabe4, LaengeFunctionPointer){
  Collatz c100{100};
  TFP fp = pcollatz;
  EXPECT_TRUE(pcollatz(42));
  EXPECT_FALSE(pcollatz(1));
  EXPECT_TRUE(laenge(c100, fp) == 25);
}

TEST(Aufgabe4, MaxLaenge){
  TFC fc = [](int a){return a != 1;};
  int n_max = maxLaenge<1000, Collatz>(fc);
  EXPECT_TRUE(n_max == 871);
  TFP fp = pcollatz;
  n_max = maxLaenge<1000, Collatz>(fp);
  EXPECT_TRUE(n_max == 871);
  PCollatz pcolFunktor{};
  n_max = maxLaenge<1000, Collatz>(pcolFunktor);
  EXPECT_TRUE(n_max == 871);
}



*/