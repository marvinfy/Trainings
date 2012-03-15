//
//  ContatoProtocol.h
//  ContatosIP67
//
//  Created by ios2534 on 14/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Contato.h"

@protocol ContatoProtocol <NSObject>

-(void) contatoAlterado;
-(void) contatoAdicionado: (Contato *) contato;

@end
