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


int main(int argc, char* argv[])
{

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

    
    PtxtArray p2(context);
    p2 = 7;
    Ctxt c2(publicKey);
    p2.encrypt(c2);

  //===========================================================================

 ofstream outContextFile;
  outContextFile.open("context.json", std::ios::out);
  if (outContextFile.is_open()) {
    // Write the context to a file
    context.writeToJSON(outContextFile);
    // Close the ofstream
    outContextFile.close();
  } else {
    throw std::runtime_error("Could not open file 'context.json'.");
  }
  
  ofstream outSecretKeyFile;
  outSecretKeyFile.open("sk.json", std::ios::out);
  if (outSecretKeyFile.is_open()) {
    // Write the secret key to a file
    secretKey.writeToJSON(outSecretKeyFile);
    // Close the ofstream
    outSecretKeyFile.close();
  } else {
    throw std::runtime_error("Could not open file 'sk.json'.");
  }

  ofstream outPublicKeyFile;
  outPublicKeyFile.open("pk.json", std::ios::out);
  if (outPublicKeyFile.is_open()) {
    // Write the public key to a file
    publicKey.writeToJSON(outPublicKeyFile);
    // Close the ofstream
    outPublicKeyFile.close();
  } else {
    throw std::runtime_error("Could not open file 'pk.json'.");
  }

  ofstream outCtxtFile;
  outCtxtFile.open("ctxt.json", std::ios::out);
  if (outCtxtFile.is_open()) {
    // Write the ctxt to a file
    c2.writeToJSON(outCtxtFile);
    // Close the ofstream
    outCtxtFile.close();
  } else {
    throw std::runtime_error("Could not open file 'ctxt.json'.");
  }

  return 0;
}
