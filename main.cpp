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

      ifstream inCtxtFile;
      inCtxtFile.open("votes.json", std::ios::in);
      if (inCtxtFile.is_open()) {
        // Read in the ctxt from the file
        helib::Ctxt c1 =
            helib::Ctxt::readFromJSON(inCtxtFile, publicKey);
        
         ifstream inCtxtFile;
        inCtxtFile2.open("newVote.json", std::ios::in);
        if (inCtxtFile2.is_open()) {    
          // Read in the ctxt from the file
          helib::Ctxt c2 =
              helib::Ctxt::readFromJSON(inCtxtFile2, publicKey);

          Ctxt c3 = c1 + c2;

          ofstream outCtxtFile;
          outCtxtFile.open("sum.json", std::ios::out);
          if (outCtxtFile.is_open()) {
            // Write the ctxt to a file
            c3.writeToJSON(outCtxtFile);
            // Close the ofstream
            outCtxtFile.close();
          } else {
            throw std::runtime_error("Could not open file 'ctxt.json'.");
          }
                  

          inCtxtFile2.close();
        } 
        else {
          throw std::runtime_error("Could not open file 'ctxt.json'.");
        }

        inCtxtFile.close();
      } 
      else {
        throw std::runtime_error("Could not open file 'ctxt.json'.");
      }
    // Close the ifstream
    inContextFile.close();
  } else {
    throw std::runtime_error("Could not open file 'context.json'.");
  }
  return 0;
}
