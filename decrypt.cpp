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
  std::ifstream inContextFile;
  inContextFile.open("context.json");
  if (inContextFile.is_open()) {
    // Read in the context from the file
    helib::Context deserializedContext =
        helib::Context::readFromJSON(inContextFile);


    std::ifstream inSecretKeyFile;
    inSecretKeyFile.open("sk.json");
    if (inSecretKeyFile.is_open()) {
      // Read in the secret key from the file
      helib::SecKey deserializedSecretKey =
          helib::SecKey::readFromJSON(inSecretKeyFile, context);

      ifstream inCtxtFile;
      inCtxtFile.open("ctxt.json", std::ios::in);
      if (inCtxtFile.is_open()) {
        // Read in the ctxt from the file
        helib::Ctxt c1 =
            helib::Ctxt::readFromJSON(inCtxtFile, publicKey);
        
        PtxtArray pp4(context);

        // Next, we decrypt c3, storing the plaintext in p3:
        pp4.decrypt(c1, sdeserializedecretKey);

        // Finally, we store the PtxtArray p3 into a standard vector v3:
        vector<double> v4;
        pp4.store(v4);

      cout<<v4.back()<<endl;

        inCtxtFile.close();
      } 
      else {
        throw std::runtime_error("Could not open file 'ctxt.json'.");
      }
      inSecretKeyFile.close();
      } 
    else {
      throw std::runtime_error("Could not open file 'sk.json'.");
      }

    // Close the ifstream
    inContextFile.close();
  } else {
    throw std::runtime_error("Could not open file 'context.json'.");
  }

  return 0;
}
