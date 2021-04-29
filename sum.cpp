/* Copyright (C) 2020-2021 IBM Corp.
 * This program is Licensed under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *   http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. See accompanying LICENSE file.
 */
#include <fstream>

#include <helib/helib.h>

using namespace helib;
using namespace std;

Context context =

      // initialize a Context object using the builder pattern
      ContextBuilder<CKKS>()
          .m(16 * 1024)
          .bits(119)
          .precision(20)
          .c(2)
          .build();
SecKey secretKey(context);
secretKey.GenSecKey();
const PubKey& publicKey = secretKey;

Ctxt encrypt(PtxtArray ptxt, PubKey publicKey)
{

    Ctxt result(publicKey);
    ptxt.encrypt(result);
    return result;
}
int main(int argc, char* argv[])
{

  /*Context context =

      // initialize a Context object using the builder pattern
      ContextBuilder<CKKS>()
          .m(16 * 1024)
          .bits(119)
          .precision(20)
          .c(2)
          .build();*/

  
 

    PtxtArray p1(context);
    p1 = 15; 
    /*Ctxt c1(publicKey);
    p1.encrypt(c1);*/
    Ctxt c1 = encrypt(p1, publicKey);
cout<<"encrypted1"<<endl;
    PtxtArray p2(context);
    p2 = 7;
    Ctxt c2(publicKey);
    p2.encrypt(c2);
cout<<"encrypted2"<<endl;
  //===========================================================================

  // Now we homorphically compute c3 = c0*c1 + c2*1.5:
  Ctxt c3 = c1;
  c3 *= c2;
  Ctxt c4 = c2;
  c4 *= 1.5;
  c3 += c4;

  PtxtArray pp4(context);

  // Next, we decrypt c3, storing the plaintext in p3:
  pp4.decrypt(c4, secretKey);

  // Finally, we store the PtxtArray p3 into a standard vector v3:
  vector<double> v4;
  pp4.store(v4);

  // Next we decrypt c3.
  // First, we construct a new PtxtArray pp3.
  PtxtArray pp3(context);

  // Next, we decrypt c3, storing the plaintext in p3:
  pp3.decrypt(c3, secretKey);

  // Finally, we store the PtxtArray p3 into a standard vector v3:
  vector<double> v3;
  pp3.store(v3);

  //===========================================================================

    cout<<v3.back()<<endl<<v4.back()<<endl;


  return 0;
}
