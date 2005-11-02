/*
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is TransforMiiX XSLT processor.
 * 
 * The Initial Developer of the Original Code is The MITRE Corporation.
 * Portions created by MITRE are Copyright (C) 1999 The MITRE Corporation.
 *
 * Portions created by Keith Visco as a Non MITRE employee,
 * (C) 1999 Keith Visco. All Rights Reserved.
 * 
 * Contributor(s): 
 * Keith Visco, kvisco@ziplink.net
 *   -- original author.
 * 
 */

#include "Expr.h"
#include "txAtoms.h"
#include "txIXPathContext.h"

  //-------------------/
 //- VariableRefExpr -/
//-------------------/

/**
 * Creates a VariableRefExpr with the given variable name
**/
VariableRefExpr::VariableRefExpr(txAtom* aPrefix, txAtom* aLocalName,
                                 PRInt32 aNSID)
    : mPrefix(aPrefix), mLocalName(aLocalName), mNamespace(aNSID)
{
    NS_ASSERTION(mLocalName, "VariableRefExpr without local name?");
    if (mPrefix == txXMLAtoms::_empty)
        mPrefix = 0;
    TX_IF_ADDREF_ATOM(mPrefix);
    TX_IF_ADDREF_ATOM(mLocalName);
}

/*
 * Release the local name atom
 */
VariableRefExpr::~VariableRefExpr()
{
    TX_IF_RELEASE_ATOM(mPrefix);
    TX_IF_RELEASE_ATOM(mLocalName);
}

/**
 * Evaluates this Expr based on the given context node and processor state
 * @param context the context node for evaluation of this Expr
 * @param ps the ContextState containing the stack information needed
 * for evaluation
 * @return the result of the evaluation
**/
ExprResult* VariableRefExpr::evaluate(txIEvalContext* aContext)
{
    ExprResult* exprResult = 0;
    nsresult rv = aContext->getVariable(mNamespace, mLocalName, exprResult);
    if (NS_FAILED(rv)) {
      // XXX report error, undefined variable
      return new StringResult("error");
    }
    return exprResult->clone();
}

/**
 * Returns the String representation of this Expr.
 * @param dest the String to use when creating the String
 * representation. The String representation will be appended to
 * any data in the destination String, to allow cascading calls to
 * other #toString() methods for Expressions.
 * @return the String representation of this Expr.
**/
void VariableRefExpr::toString(String& aDest)
{
    aDest.append('$');
    if (mPrefix) {
        String prefix;
        TX_GET_ATOM_STRING(mPrefix, prefix);
        aDest.append(prefix);
        aDest.append(':');
    }
    String lname;
    TX_GET_ATOM_STRING(mLocalName, lname);
    aDest.append(lname);
} //-- toString
