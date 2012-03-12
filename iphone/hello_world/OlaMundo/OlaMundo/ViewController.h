//
//  ViewController.h
//  OlaMundo
//
//  Created by ios2534 on 12/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property(nonatomic, weak) IBOutlet UILabel* meuLabel;
@property(nonatomic, weak) IBOutlet UITextField* meuCampoTexto;

- (IBAction)atualizaLabel:(id)sender;

@end

