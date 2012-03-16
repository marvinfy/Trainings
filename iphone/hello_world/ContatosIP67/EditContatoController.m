//
//  EditContatoController.m
//  ContatosIP67
//
//  Created by ios2534 on 15/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "EditContatoController.h"
#import "Contato.h"

@interface EditContatoController()

@property(nonatomic, strong) Contato *contato;
-(void) preencheFormularioContato;

@end


@implementation EditContatoController

@synthesize contato;

-(id)initWithContato: (Contato *) c
{
    self = [super initWithNibName: @"FormularioController" bundle:[NSBundle mainBundle]];
    
    if (self)
    {
        self.contato = c;
    }
    
    return self;
}



- (void)viewDidLoad
{
    UIBarButtonItem *confirmar = [[UIBarButtonItem alloc]
                                  initWithBarButtonSystemItem:UIBarButtonSystemItemSave
                                  target:self
                                  action:@selector(confirmar)
                                  ];
    [self preencheFormularioContato];    
    self.navigationItem.rightBarButtonItem = confirmar;
}

-(void) preencheFormularioContato
{
    self.campoNome.text = self.contato.nome;
    self.campoEmail.text = self.contato.email;
    self.campoTelefone.text = self.contato.telefone;
    self.campoEndereco.text = self.contato.endereco;
    self.campoSite.text = self.contato.site;
}


-(void) confirmar
{
    [contato setNome:self.campoNome.text];
    [contato setEmail:self.campoEmail.text];
    [contato setTelefone:self.campoTelefone.text];
    [contato setEndereco:self.campoEndereco.text];
    [contato setSite:self.campoSite.text];
    
    [self.delegate contatoAlterado];
    
    [self.navigationController popViewControllerAnimated:YES ];
}




- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView
{
}
*/

/*
// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad
{
    [super viewDidLoad];
}
*/

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

@end
