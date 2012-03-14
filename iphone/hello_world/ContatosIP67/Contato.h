//
//  Contato.h
//  ContatosIP67
//
//  Created by ios2534 on 13/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Contato : NSObject

@property (nonatomic, strong) NSString *nome;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *telefone;
@property (nonatomic, strong) NSString *endereco;
@property (nonatomic, strong) NSString *site;
@property (nonatomic, strong) UIImage *imagem;

-(Contato *) initNome: (NSString *)nome comEmail: (NSString *) email comTelefone: (NSString *) telefone comEndereco: (NSString *) endereco comSite: (NSString*) site comImagem: (UIImage *) imagem;
+(Contato *) criaContatoCompleto: (NSString*) nome comEmail: (NSString *) email comTelefone: (NSString *) telefone comEndereco: (NSString *) endereco comSite: (NSString *) site;

@end
