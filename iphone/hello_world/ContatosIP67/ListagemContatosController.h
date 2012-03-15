//
//  ListagemContatosController.h
//  ContatosIP67
//
//  Created by ios2534 on 12/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ContatoProtocol.h"

@interface ListagemContatosController : UITableViewController <ContatoProtocol>

@property (strong, nonatomic) NSMutableArray *contatos;


-(void) mostraFormContato;

@end
