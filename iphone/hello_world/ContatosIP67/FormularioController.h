//
//  FormularioController.h
//  ContatosIP67
//
//  Created by ios2534 on 14/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ContatoProtocol.h"

@interface FormularioController : UIViewController

@property (weak, nonatomic) IBOutlet UITextField *campoNome;
@property (weak, nonatomic) IBOutlet UITextField *campoEmail;
@property (weak, nonatomic) IBOutlet UITextField *campoTelefone;
@property (weak, nonatomic) IBOutlet UITextField *campoEndereco;
@property (weak, nonatomic) IBOutlet UITextField *campoSite;
@property (weak, nonatomic) IBOutlet UIButton *botaoAdicionarImagem;

@property (strong, nonatomic) id<ContatoProtocol> delegate;

@end
