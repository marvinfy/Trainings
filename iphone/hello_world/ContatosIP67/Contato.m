//
//  Contato.m
//  ContatosIP67
//
//  Created by ios2534 on 13/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "Contato.h"

@implementation Contato
@synthesize nome, email, telefone, endereco, site, imagem;


/*
 * METODO ESTATICO!
 */
+(Contato *) criaContatoCompleto: (NSString*) _nome comEmail: (NSString *) _email comTelefone: (NSString *) _telefone comEndereco: (NSString *) _endereco comSite: (NSString *) _site
{
    return [[Contato alloc] initNome:_nome comEmail:_email comTelefone:_telefone comEndereco:_endereco comSite:_site comImagem:nil];
}


/*
 * METODO DE INSTANCIA
 */
-(Contato *) initNome: (NSString *)_nome comEmail: (NSString *) _email comTelefone: (NSString *) _telefone comEndereco: (NSString *) _endereco comSite: (NSString*) _site comImagem: (UIImage *) _imagem
{
    self = [self init];
    if (self)
    {
        self.nome = _nome;
        self.email = _email;
        self.telefone = _telefone;
        self.endereco = _endereco;
        self.site = _site;
        self.imagem = _imagem;
    }
    
    return self;
}


@end
